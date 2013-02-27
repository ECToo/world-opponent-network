#include "server.hpp"

// packet headers
#include "dir.hpp"
#include "version.hpp"
#include "firewall.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <map>

server::server(const net::listener& listener, const tcp::address& dir_addr, const tcp::address& ver_addr, const tcp::address& fire_addr, const tcp::address& db_addr)
	:  mtx_(), cmtx_(), clnts_(), cnd_(),
	   ntfy_(false), dir_acpt_(listener, dir_addr),
	   ver_acpt_(listener, ver_addr), fire_acpt_(listener, fire_addr),
	   db_acpt_(listener, db_addr), thrd_()
{
#ifdef _DEBUG
	std::wcout << std::endl;
	std::wcout << L"Directory server initialized on port " << dir_addr.port() << L".\n";
	std::wcout << L"Version server (DBProxy) initialized on port " << ver_addr.port() << L".\n";
	std::wcout << L"Firewall server initialized on port " << fire_addr.port() << L".\n";
	std::wcout << L"DBProxy server initialized on port " << db_addr.port() << L".\n";
	std::wcout << std::endl;
#endif
}
 
server::~server() {
	stop();
}
 
void server::run_async() {
	thrd_.swap(std::thread(std::bind(&server::worker_thread_, this)));
}
 
void server::stop() {
	if(!running()) return;
	ntfy_ = true;
	cnd_.notify_all();
	thrd_.join();
}
 
bool server::running() const {
	return thrd_.joinable();
}
 
void server::handle_dir_(tcp::socket& socket, jodocus::buffer& buffer) {
	std::stringstream parser(std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	dir_request request;
	parser.write(reinterpret_cast<const char*>(buffer.storage()), buffer.size());
	parser >> request;

	std::vector<std::uint8_t> response_buffer;

	struct entitiy_data {
		std::uint8_t type;
		std::string address;
		std::uint16_t port;
	};

	std::ifstream ifs("titanservers.dat");
	if(!ifs)
		throw std::runtime_error("could not open titanservers.dat");
	std::map<std::wstring, entitiy_data> titan_servers;
	while(ifs) {
		std::string path;
		entitiy_data entity;
		if(ifs.eof())
			break;
		ifs >> path >> entity.type >> entity.address >> entity.port;
		if(ifs.fail())
			throw std::runtime_error("invalid titanservers.dat file");
		std::wstring wide_path;
		for(std::size_t n = 0; n < path.length(); ++n)
			wide_path.push_back(std::use_facet<std::ctype<wchar_t>>(ifs.getloc()).widen(path[n]));
		titan_servers.insert(std::make_pair(wide_path, std::move(entity)));
	}

	for(std::size_t n = 0; n < request.num_entities; ++n) {
		std::stringstream serializer(std::ios_base::in | std::ios_base::out | std::ios_base::binary);

		auto iter = titan_servers.find(request.entities[n].path);
		if(iter == titan_servers.end())
			throw std::runtime_error("titan server not supported");

		multi_dir_response response;
		response.packet_type = 5;
		response.service_type = 2;
		response.message_type = 3;
		response.status = 0;
		response.flags = 0x00000010 | 0x04000000;
		response.sequence = 0x80;
		multi_dir_response::entity_t entity;
		entity.type = iter->second.type;

		sockaddr_in saddr = { 0 };
		saddr.sin_port = htons(iter->second.port);
		saddr.sin_addr.s_addr = inet_addr(iter->second.address.c_str());

		std::memcpy(entity.address, reinterpret_cast<const sockaddr*>(&saddr)->sa_data, 14);

		response.entities.push_back(std::move(entity));
		serializer << response;

		std::string tmp = serializer.str();
		response_buffer.insert(response_buffer.end(), tmp.begin(), tmp.end());
	}

#ifdef _DEBUG 
	std::cout << std::endl << "Hex dump of Dir packet:" << std::endl;
	common::dump_hex(jodocus::buffer(response_buffer));
	std::cout << std::endl;
#endif
 
	auto si = socket.descriptor();
	socket.send(jodocus::buffer(response_buffer), [=](unsigned error, unsigned transferred) {
		if(error)
			throw net::net_error("sending error", error);
		std::lock_guard<std::mutex> lck(cmtx_);
		auto iter = clnts_.find(si);    
#ifdef _DEBUG
		if(iter != clnts_.end())
			std::wcout << L"Sent " << transferred << L" Bytes to " << iter->second.descriptor() << " (" << iter->second.peer() << L").\n";
#endif
	});

}

void server::handle_ver_(tcp::socket& socket, jodocus::buffer& buffer) {
	std::stringstream parser(std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	version_request request;
	parser.write(reinterpret_cast<const char*>(buffer.storage()), buffer.size());
	parser >> request;

	version_response response;
	std::stringstream serializer(std::ios_base::in | std::ios_base::out | std::ios_base::binary);

	response.packet_type = 5;
	response.service_type = 14;
	response.message_type = -12;
	response.submsg_type = 2;
	response.status = 0;
	response.sequence = 0x80;
	response.error_message = "";
	response.patch_info.push_back("");
	response.patch_info.push_back("");

	serializer << response;
		
	std::vector<std::uint8_t> response_buffer;
	
	std::string tmp = serializer.str();
	response_buffer.insert(response_buffer.end(), tmp.begin(), tmp.end());

#ifdef _DEBUG
	std::cout << std::endl << "Hex dump of version packet:\n";
	common::dump_hex(jodocus::buffer(response_buffer));
#endif

	auto si = socket.descriptor();
	socket.send(jodocus::buffer(response_buffer), [=](unsigned error, unsigned transferred) {
		if(error)
			throw net::net_error("sending error", error);
		std::lock_guard<std::mutex> lck(cmtx_);
		auto iter = clnts_.find(si);   
#ifdef _DEBUG
		if(iter != clnts_.end()) 
			std::wcout << L"Sent " << transferred << L" Bytes to " << iter->second.descriptor() << " (" << iter->second.peer() << L").\n";
#endif
	});
}

void server::handle_fw_(tcp::socket& socket, jodocus::buffer& buffer) {
	std::stringstream parser(std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	firewall_request request;
	parser.write(reinterpret_cast<const char*>(buffer.storage()), buffer.size());
	parser >> request;

	if(request.message_type == 1) {
		std::wstringstream wss;
		wss << request.port;
		tcp::socket c(socket.listener());
		tcp::resolver resolver(socket.listener());
		tcp::address addr = *resolver.resolve(socket.peer().ip_address(), wss.str()); // take the real port from the packet
		c.connect(addr, [](unsigned, unsigned) { });
	}

	std::stringstream serializer(std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	firewall_response response;

	response.packet_type = 5;
	response.service_type = 3;
	response.message_type = 2;
	response.status = 0;
	auto wrong_order = socket.peer().ip_address().substr(socket.peer().ip_address().find_last_of(L':') + 1);
	std::wstringstream conv(wrong_order);

	int parts[4];
	for(int i = 0; i < 4; ++i){
		conv >> parts[i];
		conv.clear();
		conv.ignore(1);
	}
	for(int i = 3; i >= 0; --i) 
		response.ipv4[3 - i] = parts[i];

	serializer << response;

	std::vector<std::uint8_t> response_buffer;
	
	std::string tmp = serializer.str();
	response_buffer.insert(response_buffer.end(), tmp.begin(), tmp.end());

#ifdef _DEBUG
	std::cout << std::endl << "Hex dump of firewall packet:\n";
	common::dump_hex(jodocus::buffer(response_buffer));
#endif

	auto si = socket.descriptor();
	socket.send(jodocus::buffer(response_buffer), [=](unsigned error, unsigned transferred) {
		if(error)
			throw net::net_error("sending error", error);
		std::lock_guard<std::mutex> lck(cmtx_);
		auto iter = clnts_.find(si);    
#ifdef _DEBUG
		if(iter != clnts_.end())
			std::wcout << L"Sent " << transferred << L" Bytes to " << iter->second.descriptor() << " (" << iter->second.peer() << L").\n";
#endif
	});
}

void server::handle_key_(tcp::socket& socket, jodocus::buffer& buffer) {
	std::stringstream ss(std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	std::uint8_t header_type = 5, seq = 0x80;
	std::uint16_t service_type = 14, message_type = 3, submsg_type = 0, status = 0;
	common::write(ss, header_type, service_type, message_type, submsg_type, status);
	std::string error_message = "";
	common::write_string(ss, error_message);
	common::write(ss, seq);
	std::string key = "VerySpecial";
	common::write_string(ss, key);

	std::uint8_t* response = new std::uint8_t[2048];
	std::uint32_t length = static_cast<std::uint32_t>(ss.str().length() + 4);
	std::memcpy(response, &length, sizeof(length));
	std::memcpy(response + sizeof length, ss.str().c_str(), ss.str().length());

#ifdef _DEBUG
	std::cout << std::endl << "Hex dump of key packet:\n";
	common::dump_hex(jodocus::buffer(response, length));
#endif

	auto si = socket.descriptor();
	socket.send(jodocus::buffer(response, length), [=](unsigned error, unsigned transferred) {
		if(error)
			throw net::net_error("sending error", error);
		std::lock_guard<std::mutex> lck(cmtx_);
		auto iter = clnts_.find(si);    
#ifdef _DEBUG
		if(iter != clnts_.end())
			std::wcout << L"Sent " << transferred << L" Bytes to " << iter->second.descriptor() << " (" << iter->second.peer() << L").\n";
#endif
	});
}
 
void server::receive_(tcp::socket& socket) {
	char buffer[512] = { 0 };
	net::native_socket_type si = socket.descriptor();
	socket.receive(jodocus::buffer(buffer, 512), [=](unsigned error, unsigned transferred) {
		if(error)
			throw net::net_error("receiving error", error);
		if(!transferred) {
			std::lock_guard<std::mutex> lck(cmtx_);
			auto iter = clnts_.find(si);
			if(iter != clnts_.end()) {    
#ifdef _DEBUG
				std::wcout << iter->second.descriptor() << L" (" << iter->second.peer() << L") closed the connection.\n";
#endif
				clnts_.erase(iter);
			}
			return;
		}
#ifdef _DEBUG
		std::wcout << L"Received " << transferred << L" Bytes!";
#endif
	});
}

void server::worker_thread_() {
	std::unique_lock<std::mutex> lck(mtx_);
	dir_acpt_.start([=](unsigned error, unsigned transferred, tcp::socket&& peer, jodocus::buffer buffer) { 
		try {
			if(error)
				throw net::net_error("accepting error", error);
 
			std::lock_guard<std::mutex> lck(cmtx_);
			tcp::socket& sock_ref = clnts_.insert(std::make_pair(peer.descriptor(), std::move(peer))).first->second;

#ifdef _DEBUG
			common::print_information_(transferred, sock_ref, buffer);
#endif
 
			try {
				handle_dir_(sock_ref, buffer);
			}
			catch(const std::runtime_error& error) {
				std::cerr << "\aRuntime error from thread " << std::this_thread::get_id() << " with message: " << error.what() << "\n";
			}
			receive_(sock_ref);
		}
		catch(const net::net_error& error) {
			std::cerr << "\aNetwork error from thread " << std::this_thread::get_id() << " with message: " << error.what() << "\n";
		}
	});

#ifdef _DEBUG
	std::cout << std::endl;
	std::cout << "Directory server processing started.\n";
#endif

	ver_acpt_.start([=](unsigned error, unsigned transferred, tcp::socket&& peer, jodocus::buffer buffer) {        
		try {
			if(error)
				throw net::net_error("accepting error", error);
 
			std::lock_guard<std::mutex> lck(cmtx_);
			tcp::socket& sock_ref = clnts_.insert(std::make_pair(peer.descriptor(), std::move(peer))).first->second;

#ifdef _DEBUG
			common::print_information_(transferred, sock_ref, buffer);
#endif

			handle_ver_(sock_ref, buffer);
			receive_(sock_ref);
		}
		catch(const net::net_error& error) {
			std::cerr << "\aNetwork error from thread " << std::this_thread::get_id() << " with message: " << error.what() << "\n";
		}
	});
	std::cout << "Version server processing started.\n";

	fire_acpt_.start([=](unsigned error, unsigned transferred, tcp::socket&& peer, jodocus::buffer buffer) {        
		try {
			if(error)
				throw net::net_error("accepting error", error);
 
			std::lock_guard<std::mutex> lck(cmtx_);
			tcp::socket& sock_ref = clnts_.insert(std::make_pair(peer.descriptor(), std::move(peer))).first->second;

#ifdef _DEBUG
			common::print_information_(transferred, sock_ref, buffer);
#endif
			handle_fw_(sock_ref, buffer);
		}
		catch(const net::net_error& error) {
			std::cerr << "\aNetwork error from thread " << std::this_thread::get_id() << " with message: " << error.what() << "\n";
		}
	});
	std::cout << "Firewall server processing started.\n";

	db_acpt_.start([=](unsigned error, unsigned transferred, tcp::socket&& peer, jodocus::buffer buffer) {        
		try {
			if(error)
				throw net::net_error("accepting error", error);
 
			std::lock_guard<std::mutex> lck(cmtx_);
			tcp::socket& sock_ref = clnts_.insert(std::make_pair(peer.descriptor(), std::move(peer))).first->second;

#ifdef _DEBUG
			common::print_information_(transferred, sock_ref, buffer);
#endif
			handle_key_(sock_ref, buffer);
			receive_(sock_ref);
			
		}
		catch(const net::net_error& error) {
			std::cerr << "\aNetwork error from thread " << std::this_thread::get_id() << " with message: " << error.what() << "\n";
		}
	});
	std::cout << "DBProxy server processing started.\n";
 
	cnd_.wait(lck, [&]() { return ntfy_; });

	db_acpt_.stop();
	fire_acpt_.stop();
	ver_acpt_.stop();
	dir_acpt_.stop();

#ifdef _DEBUG
	std::cout << "Server shut down...\n";
#endif
}