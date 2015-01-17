#include "ThreadBase.h"

#include <sys/syscall.h>
#include <pthread.h>
#include <unistd.h>

#include <errno.h>
#include <string.h>
#include <stdio.h>

namespace blink
{

namespace threads
{

pid_t gettid()
{
	return static_cast<pid_t>(::syscall(SYS_gettid));  // SYS_gettid equal 224
}

int pthread_create(pthread_t* tid, const pthread_attr_t* attr, void* (*start_routine) (void*), void* arg)
{
	int val = ::pthread_create(tid, attr, start_routine, arg);
	if (val != 0)
	{
		fprintf(stderr, "pthread_creat error: %s\n", strerror(val));
	}
	return val;
}

pthread_t pthread_self()
{
	return ::pthread_self();
}

void pthread_exit(void* thread_return)
{
	::pthread_exit(thread_return);
}

int pthread_cancel(pthread_t tid)
{
	int val = ::pthread_cancel(tid);
	if (val != 0)
	{
		fprintf(stderr, "pthread_cancesl error: %s\n", strerror(val));
	}
	return val;
}

int pthread_join(pthread_t tid, void** thread_return)
{
	int val = ::pthread_join(tid, thread_return);
	if (val != 0)
	{
		fprintf(stderr, "pthread_join error: %s\n", strerror(val));
	}
	return val;
}

int pthread_detach(pthread_t tid)
{
	int val = ::pthread_detach(tid);
	if (val != 0)
	{
		fprintf(stderr, "pthread_detach error: %s\n", strerror(val));
	}
	return val;
}

int pthread_once(pthread_once_t* once_control, void (*init_routine)())
{
	return ::pthread_once(once_control, init_routine);
}

int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr)
{
	int val = ::pthread_mutex_init(mutex, attr);
	if (val != 0)
	{
		fprintf(stderr, "pthread_mutex_init error: %s\n", strerror(val));
	}
	return val;
}

int pthread_mutex_destroy(pthread_mutex_t* mutex)
{
	int val = ::pthread_mutex_destroy(mutex);
	if (val != 0)
	{
		fprintf(stderr, "pthread_mutex_destroy error: %s\n", strerror(val));
	}
	return val;
}

int pthread_mutex_lock(pthread_mutex_t* mutex)
{
	int val = ::pthread_mutex_lock(mutex);
	if (val != 0)
	{
		fprintf(stderr, "pthread_mutex_lock error: %s\n", strerror(val));
	}
	return val;
}

int pthread_mutex_trylock(pthread_mutex_t* mutex)
{
	int val = ::pthread_mutex_trylock(mutex);
	if (val != 0 && val != EBUSY)
	{
		fprintf(stderr, "pthread_mutex_trylock error: %s\n", strerror(val));
	}
	return val;
}

int pthread_mutex_unlock(pthread_mutex_t* mutex)
{
	int val = ::pthread_mutex_unlock(mutex);
	if (val != 0)
	{
		fprintf(stderr, "pthread_mutex_unlock error: %s\n", strerror(val));
	}
	return val;
}

int pthread_cond_init(pthread_cond_t* cond, pthread_condattr_t* attr)
{
	int val = ::pthread_cond_init(cond, attr);
	if (val != 0)
	{
		fprintf(stderr, "pthread_cond_init error: %s\n", strerror(val));
	}
	return val;
}

int pthread_cond_destroy(pthread_cond_t* cond)
{
	int val = ::pthread_cond_destroy(cond);
	if (val != 0)
	{
		fprintf(stderr, "pthread_cond_destroy error: %s\n", strerror(val));
	}
	return val;
}

int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex)
{
	int val = ::pthread_cond_wait(cond, mutex);
	if (val != 0)
	{
		fprintf(stderr, "pthread_cond_wait error: %s\n", strerror(val));
	}
	return val;
}

int pthread_cond_timedwait(pthread_cond_t* cond, pthread_mutex_t* mutex, const struct timespec* timeout)
{
	int val = ::pthread_cond_timedwait(cond, mutex, timeout);
	if (val != 0)
	{
		fprintf(stderr, "pthread_cond_timewait error: %s\n", strerror(val));
	}
	return val;
}

int pthread_cond_signal(pthread_cond_t* cond)
{
	int val = ::pthread_cond_signal(cond);
	if (val != 0)
	{
		fprintf(stderr, "pthread_cond_signal error: %s\n", strerror(val));
	}
	return val;
}

int pthread_cond_broadcast(pthread_cond_t* cond)
{
	int val = ::pthread_cond_broadcast(cond);
	if (val != 0)
	{
		fprintf(stderr, "pthread_cond_broadcast error: %s\n", strerror(val));
	}
	return val;
}

}  // namespace threads

}  // namespace blink
