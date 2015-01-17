#ifndef __BLINK_CONDITION_H__
#define __BLINK_CONDITION_H__

#include "MutexLock.h"

namespace blink
{

class Condition : Nocopyable
{
public:
	explicit Condition(MutexLock& mutex);
	~Condition();

	void wait();
	void timedWait(int seconds);
	void wakeup();
	void wakeupAll();

private:
	MutexLock&      mutex_;
	pthread_cond_t  cond_;
};

}  // namespace blink

#endif
