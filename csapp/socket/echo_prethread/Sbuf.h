#ifndef __SBUF_H__
#define __SBUF_H__

#include "MutexLock.h"
#include "Condition.h"

#include <list>

template<typename Item>
class Sbuf
{
public:
	Sbuf()
		: cond_(mutex_)
	{
	}

	void insert(const Item& item)
	{
		blink::MutexLockGuard mutex_guard(mutex_);
		buf_.push_back(item);
		cond_.wakeup();
	}

	Item remove()
	{
		blink::MutexLockGuard mutex_guard(mutex_);
		while (buf_.size() == 0)
		{
			cond_.wait();
		}
		Item item = buf_.front();
		buf_.pop_front();
		return item;
	}

private:
	blink::MutexLock  mutex_;
	blink::Condition  cond_;
	std::list<Item>   buf_;
};

#endif
