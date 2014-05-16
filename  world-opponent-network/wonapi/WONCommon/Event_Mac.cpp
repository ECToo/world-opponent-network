#include "Event_Mac.h"
using namespace WONAPI;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
Event::Event(bool manualReset, bool initiallySet) 
	: mIsManualReset(manualReset), mIsSet(initiallySet)
{
// FIX:	pthread_cond_init(&mCond, 0);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Event::Set()
{
	AutoCrit autoCrit(mCrit);
	mIsSet = true;
// FIX
/*	if (!mIsSet)
	{
		if (mIsManualReset)
		{
			mIsSet = true;
			pthread_cond_broadcast(&mCond);
		}
		else
			pthread_cond_signal(&mCond);
	}	*/
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Event::Reset()
{
	AutoCrit autoCrit(mCrit);
	mIsSet = false;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool Event::WaitFor(DWORD timeout)
{
	AutoCrit autoCrit(mCrit);
	if (mIsSet)
	{
		if (!mIsManualReset)
			mIsSet = false;

		return true;
	}
// FIX:
/*	if (timeout == INFINITE)
	{
		pthread_cond_wait(&mCond, &(mCrit.mCrit));
		return true;
	}

	struct timespec waitTime = { (timeout / 1000), (timeout % 1000) * 1000000 };

	return pthread_cond_timedwait(&mCond, &(mCrit.mCrit), &waitTime) != ETIMEDOUT; */
	Sleep(timeout);
	return false;
}

