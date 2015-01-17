#ifndef __BLINK_THREADBASE_H__
#define __BLINK_THREADBASE_H__

#include <pthread.h>

namespace blink
{

namespace threads
{

pid_t gettid();

//  typedef struct
//  {
//  	int                 __detachstate;
//  	int                 __schedpolicy;
//  	struct sched_param  __schedparam;
//  	int                 __inheritsched;
//  	int                 __scope;
//  	size_t              __guardsize;
//  	int                 __stackaddr_set;
//  	void *              __stackaddr;
//  	size_t              __stacksize;
//  }pthread_attr_t;

int pthread_create(pthread_t* tid, const pthread_attr_t* attr, void* (*start_routine) (void*), void* arg);
pthread_t pthread_self();
void pthread_exit(void* thread_return);
int pthread_cancel(pthread_t tid);
int pthread_join(pthread_t tid, void** thread_return);
int pthread_detach(pthread_t tid);

//  pthread_once_t once_control = PTHREAD_ONCE_INIT;

int pthread_once(pthread_once_t* once_control, void (*init_routine)());

int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr);
int pthread_mutex_destroy(pthread_mutex_t* mutex);
int pthread_mutex_lock(pthread_mutex_t* mutex);
int pthread_mutex_trylock(pthread_mutex_t* mutex);
int pthread_mutex_unlock(pthread_mutex_t* mutex);

int pthread_cond_init(pthread_cond_t* cond, pthread_condattr_t* attr);
int pthread_cond_destroy(pthread_cond_t* cond);
int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex);

//  struct timespec
//  {
//  	time_t  tv_sec;   /* second */
//  	long    tv_nsec;  /* nanosecond */
//  };

int pthread_cond_timedwait(pthread_cond_t* cond, pthread_mutex_t* mutex, const struct timespec* timeout);
int pthread_cond_signal(pthread_cond_t* cond);
int pthread_cond_broadcast(pthread_cond_t* cond);

}  // namespace threads

}  // namespace blink

#endif
