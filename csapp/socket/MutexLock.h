#ifndef __BLINK_MUTEXLOCK_H__
#define __BLINK_MUTEXLOCK_H__

#include "Nocopyable.h"

#include <pthread.h>

namespace blink
{

class MutexLock : Nocopyable
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void trylock();
	void unlock();
	bool isLockedByCurrentThread() const;

	bool isLocked() const
	{
		return !(holder_ == 0);
	}

	pthread_mutex_t* getMutex() // non-const
	{
		return &mutex_;
	}

private:
	friend class Condition;

	class ConditionGuard
	{
	public:
		ConditionGuard(MutexLock& mutex)
			: guarder_(mutex)
		{
			guarder_.resetHolder();
		}

		~ConditionGuard()
		{
			guarder_.setHolder();
		}

	private:
		MutexLock&  guarder_;
	};

	void setHolder();

	void resetHolder()
	{
		holder_ = 0;
	}

	pthread_mutex_t  mutex_;
	pid_t            holder_;
};

class MutexLockGuard : Nocopyable
{
public:
	explicit MutexLockGuard(MutexLock& mutex);
	~MutexLockGuard();

private:
	MutexLock& mutex_;
};

}  // namespace blink

#endif
