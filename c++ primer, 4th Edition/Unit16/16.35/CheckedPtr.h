#ifndef __CHECKEDPTR_H__
#define __CHECKEDPTR_H__

#include <iostream>
#include <string>

template<typename T>
class CheckedPtr;

template<typename T>
inline bool operator==(const CheckedPtr<T> &obj1, const CheckedPtr<T> &obj2);

template<typename T>
inline bool operator!=(const CheckedPtr<T> &obj1, const CheckedPtr<T> &obj2);

template<typename T>
inline bool operator<(const CheckedPtr<T> &obj1, const CheckedPtr<T> &obj2);

template<typename T>
CheckedPtr<T> operator+(const CheckedPtr<T> &obj, const size_t n);

template<typename T>
CheckedPtr<T> operator-(const CheckedPtr<T> &obj, const size_t n);

template<typename T>
class CheckedPtr
{
public:
	CheckedPtr(T *b, T *e)
		: beg(b), end(e), curr(b) {}
		
	CheckedPtr& operator++()
	{
		if (curr == end)
		{
			std::cout << "error" << std::endl;
		}
		++curr;
		return *this;
	}

	CheckedPtr operator++(int)
	{
		CheckedPtr ret(*this);
		++*this;
		return ret;
	}

	CheckedPtr& operator--()
	{
		if (curr == beg)
		{
			std::cout << "error" << std::endl;
		}
		--curr;
		return *this;
	}

	CheckedPtr operator--(int)
	{
		CheckedPtr ret(*this);
		--*this;
		return ret;
	}

	T& operator[](const size_t index)
	{
		if ((curr + index) > end || (curr + index) < end)
		{
			std::cout << "error" << std::endl;
		}
		return *(curr + index);
	}

	const T& operator[](const size_t index) const
	{
		if ((curr + index) > end || (curr + index) < end)
		{
			std::cout << "error" << std::endl;
		}
		return *(curr + index);
	}

	T& operator*()
	{
		return *curr;
	}

	const T& operator*() const
	{
		return *curr;
	}

	friend bool operator== <T>(const CheckedPtr &obj1, const CheckedPtr &obj2);
	friend bool operator!= <T>(const CheckedPtr &obj1, const CheckedPtr &obj2);
	friend bool operator< <T>(const CheckedPtr &obj1, const CheckedPtr &obj2);
	friend CheckedPtr operator+ <T>(const CheckedPtr &obj, const size_t n);
	friend CheckedPtr operator- <T>(const CheckedPtr &obj, const size_t n);

private:
	T *beg;
	T *end;
	T *curr;
};

template<typename T>
inline bool operator==(const CheckedPtr<T> &obj1, const CheckedPtr<T> &obj2)
{
	return *(obj1.curr) == *(obj2.curr);
}

template<typename T>
inline bool operator!=(const CheckedPtr<T> &obj1, const CheckedPtr<T> &obj2)
{
	return !(obj1 == obj2);
}

template<typename T>
inline bool operator<(const CheckedPtr<T> &obj1, const CheckedPtr<T> &obj2)
{
	return *(obj1.curr) < *(obj2.curr);
}

template<typename T>
CheckedPtr<T> operator+(const CheckedPtr<T> &obj, const size_t n)
{
	if (obj.curr + n > obj.end)
	{
		std::cout << "error" << std::endl;
	}
	CheckedPtr<T> ret(obj);
	ret.curr += n;
	return ret;
}

template<typename T>
CheckedPtr<T> operator-(const CheckedPtr<T> &obj, const size_t n)
{
	if (obj.curr - n < obj.beg)
	{
		std::cout << "error" << std::endl;
	}
	CheckedPtr<T> ret(obj);
	ret.curr -= n;
	return ret;
}


#endif