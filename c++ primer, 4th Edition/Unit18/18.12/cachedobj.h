#ifndef __CHACHEDOBJ_H__
#define __CHACHEDOBJ_H__

#include <memory>
#include <stdexcept>

template<typename T>
class cachedobj
{
public:
	typedef T value_type;

	cachedobj()
		: next(NULL)
	{
	}

	virtual ~cachedobj()
	{
	}

	void* operator new(size_t size)
	{
		if (!size)
		{
			return NULL;
		}
		if (size != sizeof(value_type))
		{
			throw std::runtime_error("wrong size of object");
		}
		if (freestore == NULL)
		{
			value_type *block = alloc.allocate(length);
			for (int i = 0; i < length; ++i)
			{
				value_type *p = &block[i];
				p->cachedobj::next = freestore;
				freestore = p;
			}
		}
		value_type *p = freestore;
		freestore = freestore->cachedobj::next;
		return static_cast<void*>(p);
	}

	void operator delete(void *p, size_t size)
	{
		if (size == 0)
		{
			return;
		}
		else
		{
			value_type *target_ptr = static_cast<value_type*>(p);
			target_ptr->cachedobj::next = freestore;
			freestore = target_ptr;
		}
	}

protected:
	T *next;

private:
	static std::allocator<value_type>   alloc;
	static value_type*                  freestore;
	static size_t                       length;
};

template<typename T>
std::allocator<typename cachedobj<T>::value_type> cachedobj<T>::alloc;

template<typename T>
typename cachedobj<T>::value_type* cachedobj<T>::freestore = NULL;

template<typename T>
size_t cachedobj<T>::length = 100;

#endif