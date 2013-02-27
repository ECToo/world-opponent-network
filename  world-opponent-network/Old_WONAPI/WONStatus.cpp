#define __WON_MASTER_CPP__

#include "WONStatus.h"
#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

const char* WONAPI::WONStatusToString(WONStatus theError)
{
	switch(theError)
	{
		case WS_Success: return "WS_Success";
		case WS_Pending: return "WS_Pending";
		case WS_TimedOut: return "WS_TimedOut";
		case WS_Killed: return "WS_Killed";
		case WS_Incomplete: return "WS_Incomplete";
		case WS_None: return "WS_None";
		case WS_AwaitingCompletion: return "WS_AwaitingCompletion";
		case WS_InvalidMessage: return "WS_InvalidMessage";
		case WS_FailedToOpenFile: return "WS_FailedToOpenFile";
		case WS_FailedToWriteToFile: return "WS_FailedToWriteToFile";
		case WS_BlockMode_NotSupported: return "WS_BlockMode_NotSupported";
		case WS_AsyncMode_NotSupported: return "WS_AsyncMode_NotSupported";
		case WS_InvalidPublicKey: return "WS_InvalidPublicKey";
		case WS_MessageUnpackFailure: return "WS_MessageUnpackFailure";
		case WS_AuthRequired: return "WS_AuthRequired";
		case WS_AsyncSocket_InvalidSocket: return "WS_AsyncSocket_InvalidSocket";
		case WS_AsyncSocket_PartialSendTo: return "WS_AsyncSocket_PartialSendTo";
		case WS_AsyncSocket_StreamNotAllowed: return "WS_AsyncSocket_StreamNotAllowed";
		case WS_AsyncSocket_DatagramNotAllowed: return "WS_AsyncSocket_DatagramNotAllowed";
		case WS_AsyncSocket_Shutdown: return "WS_AsyncSocket_Shutdown";
		case WS_AsyncSocket_ConnectFailed: return "WS_AsyncSocket_ConnectFailed";
		case WS_SocketOp_InvalidSocket: return "WS_SocketOp_InvalidSocket";
		case WS_RecvMsg_InvalidLengthFieldSize: return "WS_RecvMsg_InvalidLengthFieldSize";
		case WS_RecvMsg_InvalidMessageLength: return "WS_RecvMsg_InvalidMessageLength";
		case WS_PeerAuthClient_Challenge1DecryptFailure: return "WS_PeerAuthClient_Challenge1DecryptFailure";
		case WS_PeerAuthClient_Challenge1InvalidSecretLen: return "WS_PeerAuthClient_Challenge1InvalidSecretLen";
		case WS_PeerAuthClient_Challenge1InvalidSecretKey: return "WS_PeerAuthClient_Challenge1InvalidSecretKey";
		case WS_PeerAuthClient_Challenge1CertificateUnpackFailure: return "WS_PeerAuthClient_Challenge1CertificateUnpackFailure";
		case WS_PeerAuthClient_Challenge1CertificateVerifyFailure: return "WS_PeerAuthClient_Challenge1CertificateVerifyFailure";
		case WS_PeerAuthClient_Challenge2EncryptFailure: return "WS_PeerAuthClient_Challenge2EncryptFailure";
		case WS_PeerAuthClient_CompleteDecryptFailure: return "WS_PeerAuthClient_CompleteDecryptFailure";
		case WS_PeerAuthClient_CompleteInvalidSecretLen: return "WS_PeerAuthClient_CompleteInvalidSecretLen";
		case WS_PeerAuthClient_CompleteInvalidSecretKey: return "WS_PeerAuthClient_CompleteInvalidSecretKey";
		case WS_PeerAuthClient_InvalidServiceType: return "WS_PeerAuthClient_InvalidServiceType";
		case WS_PeerAuthClient_UnexpectedChallenge: return "WS_PeerAuthClient_UnexpectedChallenge";
		case WS_PeerAuthClient_InvalidMessage: return "WS_PeerAuthClient_InvalidMessage";
		case WS_PeerAuthClient_MsgUnpackFailure: return "WS_PeerAuthClient_MsgUnpackFailure";
		case WS_PeerAuthServer_NotStarted: return "WS_PeerAuthServer_NotStarted";
		case WS_PeerAuthServer_InvalidServiceType: return "WS_PeerAuthServer_InvalidServiceType";
		case WS_PeerAuthServer_UnexpectedRequest: return "WS_PeerAuthServer_UnexpectedRequest";
		case WS_PeerAuthServer_UnexpectedChallenge: return "WS_PeerAuthServer_UnexpectedChallenge";
		case WS_PeerAuthServer_InvalidMessage: return "WS_PeerAuthServer_InvalidMessage";
		case WS_PeerAuthServer_MsgUnpackFailure: return "WS_PeerAuthServer_MsgUnpackFailure";
		case WS_PeerAuthServer_InvalidAuthMode: return "WS_PeerAuthServer_InvalidAuthMode";
		case WS_PeerAuthServer_InvalidEncryptType: return "WS_PeerAuthServer_InvalidEncryptType";
		case WS_PeerAuthServer_InvalidClientCertificate: return "WS_PeerAuthServer_InvalidClientCertificate";
		case WS_PeerAuthServer_ExpiredClientCertificate: return "WS_PeerAuthServer_ExpiredClientCertificate";
		case WS_PeerAuthServer_FailedToVerifyClientCertificate: return "WS_PeerAuthServer_FailedToVerifyClientCertificate";
		case WS_PeerAuthServer_FailedToEncryptWithClientPubKey: return "WS_PeerAuthServer_FailedToEncryptWithClientPubKey";
		case WS_PeerAuthServer_FailedToDecryptWithPrivateKey: return "WS_PeerAuthServer_FailedToDecryptWithPrivateKey";
		case WS_PeerAuthServer_InvalidSecretA: return "WS_PeerAuthServer_InvalidSecretA";
		case WS_PeerAuthServer_InvalidSecretB: return "WS_PeerAuthServer_InvalidSecretB";
		case WS_PeerAuth_GetCertFailure: return "WS_PeerAuth_GetCertFailure";
		case WS_ServerReq_FailedAllServers: return "WS_ServerReq_FailedAllServers";
		case WS_ServerReq_NoServersSpecified: return "WS_ServerReq_NoServersSpecified";
		case WS_ServerReq_NeedAuthContext: return "WS_ServerReq_NeedAuthContext";
		case WS_ServerReq_TryNextServer: return "WS_ServerReq_TryNextServer";
		case WS_ServerReq_Send: return "WS_ServerReq_Send";
		case WS_ServerReq_Recv: return "WS_ServerReq_Recv";
		case WS_ServerReq_ExitCommunicationLoop: return "WS_ServerReq_ExitCommunicationLoop";
		case WS_ServerReq_SessionExpired: return "WS_ServerReq_SessionExpired";
		case WS_ServerReq_GetCertFailure: return "WS_ServerReq_GetCertFailure";
		case WS_ServerReq_InvalidReplyHeader: return "WS_ServerReq_InvalidReplyHeader";
		case WS_ServerReq_UnpackFailure: return "WS_ServerReq_UnpackFailure";
		case WS_GetCert_PubKeyEncryptFailure: return "WS_GetCert_PubKeyEncryptFailure";
		case WS_GetCert_InvalidPubKeyReply: return "WS_GetCert_InvalidPubKeyReply";
		case WS_GetCert_InvalidLoginReply: return "WS_GetCert_InvalidLoginReply";
		case WS_GetCert_UnableToFindHashFile: return "WS_GetCert_UnableToFindHashFile";
		case WS_GetCert_UnexpectedLoginChallenge: return "WS_GetCert_UnexpectedLoginChallenge";
		case WS_GetCert_NeedVerifierKey: return "WS_GetCert_NeedVerifierKey";
		case WS_GetCert_FailedToVerifyPubKeyBlock: return "WS_GetCert_FailedToVerifyPubKeyBlock";
		case WS_GetCert_InvalidCertificate: return "WS_GetCert_InvalidCertificate";
		case WS_GetCert_InvalidPubKeyBlock: return "WS_GetCert_InvalidPubKeyBlock";
		case WS_GetCert_DecryptFailure: return "WS_GetCert_DecryptFailure";
		case WS_GetCert_InvalidPrivateKey: return "WS_GetCert_InvalidPrivateKey";
		case WS_GetCert_InvalidSecretConfirm: return "WS_GetCert_InvalidSecretConfirm";
		case WS_GetCert_MissingCertificate: return "WS_GetCert_MissingCertificate";
		case WS_AuthData_SetCertificateUnpackFailed: return "WS_AuthData_SetCertificateUnpackFailed";
		case WS_AuthData_SetPubKeyBlockUnpackFailed: return "WS_AuthData_SetPubKeyBlockUnpackFailed";
		case WS_AuthData_SetCertificateVerifyFailed: return "WS_AuthData_SetCertificateVerifyFailed";
		case WS_AuthData_SetPrivateKeyFailed: return "WS_AuthData_SetPrivateKeyFailed";
		case WS_AuthSession_EncryptFailure: return "WS_AuthSession_EncryptFailure";
		case WS_AuthSession_DecryptSessionIdMismatch: return "WS_AuthSession_DecryptSessionIdMismatch";
		case WS_AuthSession_DecryptFailure: return "WS_AuthSession_DecryptFailure";
		case WS_AuthSession_DecryptBadLen: return "WS_AuthSession_DecryptBadLen";
		case WS_AuthSession_DecryptInvalidSequenceNum: return "WS_AuthSession_DecryptInvalidSequenceNum";
		case WS_AuthSession_DecryptUnpackFailure: return "WS_AuthSession_DecryptUnpackFailure";
		case WS_ServerConnection_RecvNotAllowedInAsyncMode: return "WS_ServerConnection_RecvNotAllowedInAsyncMode";
		case WS_FTP_InvalidResponse: return "WS_FTP_InvalidResponse";
		case WS_FTP_StatusError: return "WS_FTP_StatusError";
		case WS_FTP_InvalidPasvResponse: return "WS_FTP_InvalidPasvResponse";
		case WS_HTTP_InvalidHeader: return "WS_HTTP_InvalidHeader";
		case WS_HTTP_StatusError: return "WS_HTTP_StatusError";
		case WS_HTTP_InvalidRedirect: return "WS_HTTP_InvalidRedirect";
		case WS_HTTP_TooManyRedirects: return "WS_HTTP_TooManyRedirects";
		case WS_GetMOTD_SysNotFound: return "WS_GetMOTD_SysNotFound";
		case WS_GetMOTD_GameNotFound: return "WS_GetMOTD_GameNotFound";
		case WS_BaseMsgRequest_NoRequest: return "WS_BaseMsgRequest_NoRequest";
		case WS_BaseMsgRequest_UnpackFailure: return "WS_BaseMsgRequest_UnpackFailure";
		case WS_BaseMsgRequest_BadHeaderType: return "WS_BaseMsgRequest_BadHeaderType";
		case WS_RoutingOp_ReplyUnpackFailure: return "WS_RoutingOp_ReplyUnpackFailure";
		case WS_RoutingOp_DontWantReply: return "WS_RoutingOp_DontWantReply";
		case WS_RoutingOp_NeedMoreReplies: return "WS_RoutingOp_NeedMoreReplies";
		case WS_GameSpySupport_UnhandledError: return "WS_GameSpySupport_UnhandledError";
		case WS_GameSpySupport_WinSockError: return "WS_GameSpySupport_WinSockError";
		case WS_GameSpySupport_BindError: return "WS_GameSpySupport_BindError";
		case WS_GameSpySupport_DNSError: return "WS_GameSpySupport_DNSError";
		case WS_GameSpySupport_ConnError: return "WS_GameSpySupport_ConnError";
		case WS_CommServ_Failure: return "WS_CommServ_Failure";
		case WS_CommServ_NotAvailable: return "WS_CommServ_NotAvailable";
		case WS_CommServ_NotAllowed: return "WS_CommServ_NotAllowed";
		case WS_CommServ_InvalidParameters: return "WS_CommServ_InvalidParameters";
		case WS_CommServ_AlreadyExists: return "WS_CommServ_AlreadyExists";
		case WS_CommServ_MessageExceedsMax: return "WS_CommServ_MessageExceedsMax";
		case WS_CommServ_SessionNotFound: return "WS_CommServ_SessionNotFound";
		case WS_CommServ_NotAuthorized: return "WS_CommServ_NotAuthorized";
		case WS_CommServ_ResourcesLow: return "WS_CommServ_ResourcesLow";
		case WS_CommServ_NoPortAvailable: return "WS_CommServ_NoPortAvailable";
		case WS_CommServ_TimedOut: return "WS_CommServ_TimedOut";
		case WS_CommServ_NotSupported: return "WS_CommServ_NotSupported";
		case WS_CommServ_DecryptionFailed: return "WS_CommServ_DecryptionFailed";
		case WS_CommServ_InvalidSessionId: return "WS_CommServ_InvalidSessionId";
		case WS_CommServ_InvalidSequenceNumber: return "WS_CommServ_InvalidSequenceNumber";
		case WS_CommServ_InvalidMessage: return "WS_CommServ_InvalidMessage";
		case WS_CommServ_BehindFirewall: return "WS_CommServ_BehindFirewall";
		case WS_CommServ_BadPeerCertificate: return "WS_CommServ_BadPeerCertificate";
		case WS_CommServ_ExpiredPeerCertificate: return "WS_CommServ_ExpiredPeerCertificate";
		case WS_CommServ_StatusCommon_BannedAddress: return "WS_CommServ_StatusCommon_BannedAddress";
		case WS_AuthServ_FailureStart: return "WS_AuthServ_FailureStart";
		case WS_AuthServ_BadPubKeyBlock: return "WS_AuthServ_BadPubKeyBlock";
		case WS_AuthServ_BadCDKey: return "WS_AuthServ_BadCDKey";
		case WS_AuthServ_CDKeyBanned: return "WS_AuthServ_CDKeyBanned";
		case WS_AuthServ_CDKeyInUse: return "WS_AuthServ_CDKeyInUse";
		case WS_AuthServ_CRCFailed: return "WS_AuthServ_CRCFailed";
		case WS_AuthServ_UserExists: return "WS_AuthServ_UserExists";
		case WS_AuthServ_UserNotFound: return "WS_AuthServ_UserNotFound";
		case WS_AuthServ_BadPassword: return "WS_AuthServ_BadPassword";
		case WS_AuthServ_InvalidUserName: return "WS_AuthServ_InvalidUserName";
		case WS_AuthServ_BadCommunity: return "WS_AuthServ_BadCommunity";
		case WS_AuthServ_InvalidCDKey: return "WS_AuthServ_InvalidCDKey";
		case WS_AuthServ_NotInCommunity: return "WS_AuthServ_NotInCommunity";
		case WS_AuthServ_UserSeqInUse: return "WS_AuthServ_UserSeqInUse";
		case WS_AuthServ_SetCUDError: return "WS_AuthServ_SetCUDError";
		case WS_DirServ_FailureStart: return "WS_DirServ_FailureStart";
		case WS_DirServ_DirNotFound: return "WS_DirServ_DirNotFound";
		case WS_DirServ_ServiceNotFound: return "WS_DirServ_ServiceNotFound";
		case WS_DirServ_DirExists: return "WS_DirServ_DirExists";
		case WS_DirServ_ServiceExists: return "WS_DirServ_ServiceExists";
		case WS_DirServ_DirIsFull: return "WS_DirServ_DirIsFull";
		case WS_DirServ_AlreadyConnected: return "WS_DirServ_AlreadyConnected";
		case WS_DirServ_EntityTooLarge: return "WS_DirServ_EntityTooLarge";
		case WS_DirServ_MaxDataObjects: return "WS_DirServ_MaxDataObjects";
		case WS_DirServ_BadDataOffset: return "WS_DirServ_BadDataOffset";
		case WS_DirServ_InvalidPath: return "WS_DirServ_InvalidPath";
		case WS_DirServ_InvalidGetFlags: return "WS_DirServ_InvalidGetFlags";
		case WS_DirServ_InvalidKey: return "WS_DirServ_InvalidKey";
		case WS_DirServ_InvalidMode: return "WS_DirServ_InvalidMode";
		case WS_DirServ_InvalidLifespan: return "WS_DirServ_InvalidLifespan";
		case WS_DirServ_InvalidDataObject: return "WS_DirServ_InvalidDataObject";
		case WS_DirServ_NoDataObjects: return "WS_DirServ_NoDataObjects";
		case WS_DirServ_DataObjectExists: return "WS_DirServ_DataObjectExists";
		case WS_DirServ_DataObjectNotFound: return "WS_DirServ_DataObjectNotFound";
		case WS_DirServ_InvalidACLType: return "WS_DirServ_InvalidACLType";
		case WS_DirServ_PermissionExists: return "WS_DirServ_PermissionExists";
		case WS_DirServ_PermissionNotFound: return "WS_DirServ_PermissionNotFound";
		case WS_DirServ_MaxPermissions: return "WS_DirServ_MaxPermissions";
		case WS_DirServ_NoACLs: return "WS_DirServ_NoACLs";
		case WS_DirServ_MultiGetPartialFailure: return "WS_DirServ_MultiGetPartialFailure";
		case WS_DirServ_MultiGetFailedAllRequests: return "WS_DirServ_MultiGetFailedAllRequests";
		case WS_EventServ_FailureStart: return "WS_EventServ_FailureStart";
		case WS_EventServ_BufferingError: return "WS_EventServ_BufferingError";
		case WS_EventServ_InvalidDateTime: return "WS_EventServ_InvalidDateTime";
		case WS_EventServ_InvalidDataType: return "WS_EventServ_InvalidDataType";
		case WS_RoutingServG2_BlankNamesNotAllowed: return "WS_RoutingServG2_BlankNamesNotAllowed";
		case WS_RoutingServG2_CaptainRejectedYou: return "WS_RoutingServG2_CaptainRejectedYou";
		case WS_RoutingServG2_ClientAlreadyBanned: return "WS_RoutingServG2_ClientAlreadyBanned";
		case WS_RoutingServG2_ClientAlreadyExists: return "WS_RoutingServG2_ClientAlreadyExists";
		case WS_RoutingServG2_ClientAlreadyInGroup: return "WS_RoutingServG2_ClientAlreadyInGroup";
		case WS_RoutingServG2_ClientAlreadyMuted: return "WS_RoutingServG2_ClientAlreadyMuted";
		case WS_RoutingServG2_ClientAlreadyRegistered: return "WS_RoutingServG2_ClientAlreadyRegistered";
		case WS_RoutingServG2_ClientBanned: return "WS_RoutingServG2_ClientBanned";
		case WS_RoutingServG2_ClientDoesNotExist: return "WS_RoutingServG2_ClientDoesNotExist";
		case WS_RoutingServG2_ClientNotBanned: return "WS_RoutingServG2_ClientNotBanned";
		case WS_RoutingServG2_ClientNotInGroup: return "WS_RoutingServG2_ClientNotInGroup";
		case WS_RoutingServG2_ClientNotInvited: return "WS_RoutingServG2_ClientNotInvited";
		case WS_RoutingServG2_ClientNotMuted: return "WS_RoutingServG2_ClientNotMuted";
		case WS_RoutingServG2_ClientNotPermitted: return "WS_RoutingServG2_ClientNotPermitted";
		case WS_RoutingServG2_ConnectFailure: return "WS_RoutingServG2_ConnectFailure";
		case WS_RoutingServG2_DuplicateDataObject: return "WS_RoutingServG2_DuplicateDataObject";
		case WS_RoutingServG2_GroupAlreadyClaimed: return "WS_RoutingServG2_GroupAlreadyClaimed";
		case WS_RoutingServG2_GroupAlreadyExists: return "WS_RoutingServG2_GroupAlreadyExists";
		case WS_RoutingServG2_GroupClosed: return "WS_RoutingServG2_GroupClosed";
		case WS_RoutingServG2_GroupDeleted: return "WS_RoutingServG2_GroupDeleted";
		case WS_RoutingServG2_GroupDoesNotExist: return "WS_RoutingServG2_GroupDoesNotExist";
		case WS_RoutingServG2_GroupFull: return "WS_RoutingServG2_GroupFull";
		case WS_RoutingServG2_GuestNamesReserved: return "WS_RoutingServG2_GuestNamesReserved";
		case WS_RoutingServG2_InvalidContentType: return "WS_RoutingServG2_InvalidContentType";
		case WS_RoutingServG2_InvalidPassword: return "WS_RoutingServG2_InvalidPassword";
		case WS_RoutingServG2_InvalidWONUserId: return "WS_RoutingServG2_InvalidWONUserId";
		case WS_RoutingServG2_LoginTypeNotSupported: return "WS_RoutingServG2_LoginTypeNotSupported";
		case WS_RoutingServG2_MustBeAdmin: return "WS_RoutingServG2_MustBeAdmin";
		case WS_RoutingServG2_MustBeAuthenticated: return "WS_RoutingServG2_MustBeAuthenticated";
		case WS_RoutingServG2_MustBeCaptain: return "WS_RoutingServG2_MustBeCaptain";
		case WS_RoutingServG2_MustBeCaptainOrModerator: return "WS_RoutingServG2_MustBeCaptainOrModerator";
		case WS_RoutingServG2_MustBeClient: return "WS_RoutingServG2_MustBeClient";
		case WS_RoutingServG2_MustBeModerator: return "WS_RoutingServG2_MustBeModerator";
		case WS_RoutingServG2_MustBeSelf: return "WS_RoutingServG2_MustBeSelf";
		case WS_RoutingServG2_MustBeVisible: return "WS_RoutingServG2_MustBeVisible";
		case WS_RoutingServG2_NoPendingJoin: return "WS_RoutingServG2_NoPendingJoin";
		case WS_RoutingServG2_NoUsernameInCertificate: return "WS_RoutingServG2_NoUsernameInCertificate";
		case WS_RoutingServG2_ObjectDoesNotExist: return "WS_RoutingServG2_ObjectDoesNotExist";
		case WS_RoutingServG2_ObserversNotAllowed: return "WS_RoutingServG2_ObserversNotAllowed";
		case WS_RoutingServG2_OffsetTooLarge: return "WS_RoutingServG2_OffsetTooLarge";
		case WS_RoutingServG2_Pending: return "WS_RoutingServG2_Pending";
		case WS_RoutingServG2_ServerFull: return "WS_RoutingServG2_ServerFull";
		case WS_RoutingServG2_ShutdownTimerAlreadyExists: return "WS_RoutingServG2_ShutdownTimerAlreadyExists";
		case WS_RoutingServG2_ShutdownTimerDoesNotExist: return "WS_RoutingServG2_ShutdownTimerDoesNotExist";
		case WS_RoutingServG2_SubscriptionAlreadyExists: return "WS_RoutingServG2_SubscriptionAlreadyExists";
		case WS_RoutingServG2_SubscriptionDoesNotExist: return "WS_RoutingServG2_SubscriptionDoesNotExist";
		case WS_RoutingServG2_SubscriptionDoesNotExists: return "WS_RoutingServG2_SubscriptionDoesNotExists";
		case WS_RoutingServG2_Throttled: return "WS_RoutingServG2_Throttled";
		case WS_RoutingServG2_TooManyMemberships: return "WS_RoutingServG2_TooManyMemberships";
		case WS_RoutingServG2_TooManyRecipients: return "WS_RoutingServG2_TooManyRecipients";
		case WS_ProfileServ_ProfileDoesNotExist: return "WS_ProfileServ_ProfileDoesNotExist";
		case WS_ProfileServ_UserNotFound: return "WS_ProfileServ_UserNotFound";
		case WS_ProfileServ_AgeRangeNotFound: return "WS_ProfileServ_AgeRangeNotFound";
		case WS_ProfileServ_CountryNotFound: return "WS_ProfileServ_CountryNotFound";
		case WS_ProfileServ_PartySeqAlreadySet: return "WS_ProfileServ_PartySeqAlreadySet";
		case WS_ProfileServ_EmailAlreadyUsed: return "WS_ProfileServ_EmailAlreadyUsed";
		case WS_ProfileServ_NewsletterEntryExists: return "WS_ProfileServ_NewsletterEntryExists";
		case WS_ProfileServ_PartySourceEntryExists: return "WS_ProfileServ_PartySourceEntryExists";
		case WS_ProfileServ_BadWONUserPassword: return "WS_ProfileServ_BadWONUserPassword";
		case WS_ProfileServ_WONUserAlreadyExists: return "WS_ProfileServ_WONUserAlreadyExists";
		case WS_ProfileServ_DatabaseError: return "WS_ProfileServ_DatabaseError";
		case WS_ProfileServ_InvalidWONUserName: return "WS_ProfileServ_InvalidWONUserName";
		case WS_ProfileServ_AccountCreationDisabled: return "WS_ProfileServ_AccountCreationDisabled";
		case WS_ProfileServ_OtherError: return "WS_ProfileServ_OtherError";
		case WS_ProfileServ_UnfoundNewsletterName: return "WS_ProfileServ_UnfoundNewsletterName";
		case WS_ProfileServ_TooManyNewsletters: return "WS_ProfileServ_TooManyNewsletters";
		case WS_ProfileServ_NoNewslettersProvided: return "WS_ProfileServ_NoNewslettersProvided";
		case WS_ProfileServ_RemoveNewsLettersFailed: return "WS_ProfileServ_RemoveNewsLettersFailed";
		case WS_DBProxyServ_DBError: return "WS_DBProxyServ_DBError";
		case WS_DBProxyServ_NoData: return "WS_DBProxyServ_NoData";
		case WS_DBProxyServ_NoModule: return "WS_DBProxyServ_NoModule";
		case WS_DBProxyServ_UserExists: return "WS_DBProxyServ_UserExists";
		case WS_DBProxyServ_InvalidUserName: return "WS_DBProxyServ_InvalidUserName";
		case WS_DBProxyServ_KeyInUse: return "WS_DBProxyServ_KeyInUse";
		case WS_DBProxyServ_UserDoesNotExist: return "WS_DBProxyServ_UserDoesNotExist";
		case WS_DBProxyServ_InvalidCDKey: return "WS_DBProxyServ_InvalidCDKey";
		case WS_DBProxyServ_KeyNotUsed: return "WS_DBProxyServ_KeyNotUsed";
		case WS_DBProxyServ_EMailPasswordDuplication: return "WS_DBProxyServ_EMailPasswordDuplication";
		case WS_DBProxyServ_AccountCreateDisabled: return "WS_DBProxyServ_AccountCreateDisabled";
		case WS_DBProxyServ_InvalidPassword: return "WS_DBProxyServ_InvalidPassword";
		case WS_DBProxyServ_AgeNotOldEnough: return "WS_DBProxyServ_AgeNotOldEnough";
		case WS_DBProxyServ_ItemHasDependencies: return "WS_DBProxyServ_ItemHasDependencies";
		case WS_DBProxyServ_OutOfDate: return "WS_DBProxyServ_OutOfDate";
		case WS_DBProxyServ_OutOfDateNoUpdate: return "WS_DBProxyServ_OutOfDateNoUpdate";
		case WS_DBProxyServ_ValidNotLatest: return "WS_DBProxyServ_ValidNotLatest";
		case WS_DBProxyServ_GameSpecificErrorStart: return "WS_DBProxyServ_GameSpecificErrorStart";
		case WS_DBProxyServ_GameSpecificWarriorNameDoesNotExist: return "WS_DBProxyServ_GameSpecificWarriorNameDoesNotExist";
		case WS_DBProxyServ_GameSpecificErrorEnd: return "WS_DBProxyServ_GameSpecificErrorEnd";
#ifdef WIN32
		case WS_WSAEINTR: return "WS_WSAEINTR";
		case WS_WSAEBADF: return "WS_WSAEBADF";
		case WS_WSAEACCES: return "WS_WSAEACCES";
		case WS_WSAEFAULT: return "WS_WSAEFAULT";
		case WS_WSAEINVAL: return "WS_WSAEINVAL";
		case WS_WSAEMFILE: return "WS_WSAEMFILE";
		case WS_WSAEWOULDBLOCK: return "WS_WSAEWOULDBLOCK";
		case WS_WSAEINPROGRESS: return "WS_WSAEINPROGRESS";
		case WS_WSAEALREADY: return "WS_WSAEALREADY";
		case WS_WSAENOTSOCK: return "WS_WSAENOTSOCK";
		case WS_WSAEDESTADDRREQ: return "WS_WSAEDESTADDRREQ";
		case WS_WSAEMSGSIZE: return "WS_WSAEMSGSIZE";
		case WS_WSAEPROTOTYPE: return "WS_WSAEPROTOTYPE";
		case WS_WSAENOPROTOOPT: return "WS_WSAENOPROTOOPT";
		case WS_WSAEPROTONOSUPPORT: return "WS_WSAEPROTONOSUPPORT";
		case WS_WSAESOCKTNOSUPPORT: return "WS_WSAESOCKTNOSUPPORT";
		case WS_WSAEOPNOTSUPP: return "WS_WSAEOPNOTSUPP";
		case WS_WSAEPFNOSUPPORT: return "WS_WSAEPFNOSUPPORT";
		case WS_WSAEAFNOSUPPORT: return "WS_WSAEAFNOSUPPORT";
		case WS_WSAEADDRINUSE: return "WS_WSAEADDRINUSE";
		case WS_WSAEADDRNOTAVAIL: return "WS_WSAEADDRNOTAVAIL";
		case WS_WSAENETDOWN: return "WS_WSAENETDOWN";
		case WS_WSAENETUNREACH: return "WS_WSAENETUNREACH";
		case WS_WSAENETRESET: return "WS_WSAENETRESET";
		case WS_WSAECONNABORTED: return "WS_WSAECONNABORTED";
		case WS_WSAECONNRESET: return "WS_WSAECONNRESET";
		case WS_WSAENOBUFS: return "WS_WSAENOBUFS";
		case WS_WSAEISCONN: return "WS_WSAEISCONN";
		case WS_WSAENOTCONN: return "WS_WSAENOTCONN";
		case WS_WSAESHUTDOWN: return "WS_WSAESHUTDOWN";
		case WS_WSAETOOMANYREFS: return "WS_WSAETOOMANYREFS";
		case WS_WSAETIMEDOUT: return "WS_WSAETIMEDOUT";
		case WS_WSAECONNREFUSED: return "WS_WSAECONNREFUSED";
		case WS_WSAELOOP: return "WS_WSAELOOP";
		case WS_WSAENAMETOOLONG: return "WS_WSAENAMETOOLONG";
		case WS_WSAEHOSTDOWN: return "WS_WSAEHOSTDOWN";
		case WS_WSAEHOSTUNREACH: return "WS_WSAEHOSTUNREACH";
		case WS_WSAENOTEMPTY: return "WS_WSAENOTEMPTY";
		case WS_WSAEPROCLIM: return "WS_WSAEPROCLIM";
		case WS_WSAEUSERS: return "WS_WSAEUSERS";
		case WS_WSAEDQUOT: return "WS_WSAEDQUOT";
		case WS_WSAESTALE: return "WS_WSAESTALE";
		case WS_WSAEREMOTE: return "WS_WSAEREMOTE";
		case WS_WSASYSNOTREADY: return "WS_WSASYSNOTREADY";
		case WS_WSAVERNOTSUPPORTED: return "WS_WSAVERNOTSUPPORTED";
		case WS_WSANOTINITIALISED: return "WS_WSANOTINITIALISED";
		case WS_WSAEDISCON: return "WS_WSAEDISCON";
#else
		case WS_WSAEINTR: return "WS_WSAEINTR";
		case WS_WSAEBADF: return "WS_WSAEBADF";
		case WS_WSAEACCES: return "WS_WSAEACCES";
		case WS_WSAEFAULT: return "WS_WSAEFAULT";
		case WS_WSAEINVAL: return "WS_WSAEINVAL";
		case WS_WSAEMFILE: return "WS_WSAEMFILE";
		case WS_WSAEWOULDBLOCK: return "WS_WSAEWOULDBLOCK";
		case WS_WSAEINPROGRESS: return "WS_WSAEINPROGRESS";
		case WS_WSAEALREADY: return "WS_WSAEALREADY";
		case WS_WSAENOTSOCK: return "WS_WSAENOTSOCK";
		case WS_WSAEDESTADDRREQ: return "WS_WSAEDESTADDRREQ";
		case WS_WSAEMSGSIZE: return "WS_WSAEMSGSIZE";
		case WS_WSAEPROTOTYPE: return "WS_WSAEPROTOTYPE";
		case WS_WSAENOPROTOOPT: return "WS_WSAENOPROTOOPT";
		case WS_WSAEPROTONOSUPPORT: return "WS_WSAEPROTONOSUPPORT";
		case WS_WSAESOCKTNOSUPPORT: return "WS_WSAESOCKTNOSUPPORT";
		case WS_WSAEOPNOTSUPP: return "WS_WSAEOPNOTSUPP";
		case WS_WSAEPFNOSUPPORT: return "WS_WSAEPFNOSUPPORT";
		case WS_WSAEAFNOSUPPORT: return "WS_WSAEAFNOSUPPORT";
		case WS_WSAEADDRINUSE: return "WS_WSAEADDRINUSE";
		case WS_WSAEADDRNOTAVAIL: return "WS_WSAEADDRNOTAVAIL";
		case WS_WSAENETDOWN: return "WS_WSAENETDOWN";
		case WS_WSAENETUNREACH: return "WS_WSAENETUNREACH";
		case WS_WSAENETRESET: return "WS_WSAENETRESET";
		case WS_WSAECONNABORTED: return "WS_WSAECONNABORTED";
		case WS_WSAECONNRESET: return "WS_WSAECONNRESET";
		case WS_WSAENOBUFS: return "WS_WSAENOBUFS";
		case WS_WSAEISCONN: return "WS_WSAEISCONN";
		case WS_WSAENOTCONN: return "WS_WSAENOTCONN";
		case WS_WSAESHUTDOWN: return "WS_WSAESHUTDOWN";
		case WS_WSAETOOMANYREFS: return "WS_WSAETOOMANYREFS";
		case WS_WSAETIMEDOUT: return "WS_WSAETIMEDOUT";
		case WS_WSAECONNREFUSED: return "WS_WSAECONNREFUSED";
		case WS_WSAELOOP: return "WS_WSAELOOP";
		case WS_WSAENAMETOOLONG: return "WS_WSAENAMETOOLONG";
		case WS_WSAEHOSTDOWN: return "WS_WSAEHOSTDOWN";
		case WS_WSAEHOSTUNREACH: return "WS_WSAEHOSTUNREACH";
		case WS_WSAHOST_NOT_FOUND: return "WS_WSAHOST_NOT_FOUND";
		case WS_EPIPE: return "WS_EPIPE";
#endif // WIN32
		default: { static char aBuf[1024]; if(theError<=-2900 && theError>=-2999) sprintf(aBuf,"DBProxyServ_GameSpecificError%d",theError); else sprintf(aBuf,"%d",theError); return aBuf; }
	}
}
