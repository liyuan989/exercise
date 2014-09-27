#ifndef __HANDLE_H__
#define __HANDLE_H__

#include <cstddef>
#include <stdexcept>

template<typename T>
class Handle
{
public:
	Handle(T *p = NULL)
		: ptr(p), use(new size_t(1)) { }

	Handle(const Handle &obj)
		: ptr(obj.ptr), use(obj.use)
	{
		++*use;
	}

	~Handle()
	{
		rem_ref();
	}

	Handle& operator=(const Handle &obj)
	{
		++*obj.use;
		rem_ref();
		ptr = obj.ptr;
		use = obj.use;
		return *this;
	}

	T& operator*()
	{
		if (ptr)
		{
			return *ptr;
		}
		throw std::runtime_error("dereference of unbound Handle");
	}

	const T& operator*() const
	{
		if (ptr)
		{
			return *ptr;
		}
		throw std::runtime_error("dereference of unbound Handle");
	}

	T* operator->()
	{
		if (ptr)
		{
			return ptr;
		}
		throw std::runtime_error("access through unbound Handle");
	}

	const T* operator->() const
	{
		if (ptr)
		{
			return ptr;
		}
		throw std::runtime_error("access through unbound Handle");
	}

private:
	void rem_ref()
	{
		if (--*use == 0)
		{
			delete ptr;
			delete use;
		}
	}

	T 		*ptr;
	size_t  *use;
};

#endif