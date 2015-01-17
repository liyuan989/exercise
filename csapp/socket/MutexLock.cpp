#include "MutexLock.h"
#include "ThreadBase.h"

namespace blink
{

MutexLock::MutexLock()
	: holder_(0)
{
	threads::pthread_mutex_init(&mutex_, NULL);
}

MutexLock::~MutexLock()
{
	threads::pthread_mutex_destroy(&mutex_);
}

void MutexLock::lock()
{
	if (threads::pthread_mutex_lock(&mutex_) == 0)
	{
		setHolder();
	}
}

void MutexLock::trylock()
{
	if (threads::pthread_mutex_trylock(&mutex_) == 0)
	{
		setHolder();
	}
}

void MutexLock::unlock()
{
	if (threads::pthread_mutex_unlock(&mutex_) == 0)
	{
		resetHolder();
	}
}

bool MutexLock::isLockedByCurrentThread() const
{
	return holder_ == threads::gettid();
}

void MutexLock::setHolder()
{
	holder_ = threads::gettid();
}

MutexLockGuard::MutexLockGuard(MutexLock& mutex)
	: mutex_(mutex)
{
	mutex_.lock();
}

MutexLockGuard::~MutexLockGuard()
{
	mutex_.unlock();
}

}  // namespace blink
