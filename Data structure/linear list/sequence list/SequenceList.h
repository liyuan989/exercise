#ifndef __SEQUENCELIST_H__
#define __SEQUENCELIST_H__

#ifndef NULL
#define NULL 0
#endif

template<typename T>
class SequenceList
{
public:
	typedef T        value_type;

	SequenceList()
		: first(NULL), last(NULL), end_ptr(NULL)
	{
	}

	explicit SequenceList(int size)
		: first(NULL), last(NULL), end_ptr(NULL)
	{
		init(size);
	}

	~SequenceList()
	{
		destroy();
	}

	T* begin()
	{
		return first;
	}

	const T* begin() const
	{
		return first;
	}

	T* end()
	{
		return last;
	}

	const T* end() const
	{
		return last;
	}

	bool empty() const
	{
		return !(last - first);
	}

	int length() const
	{
		return last - first;
	}

	T* insert(T* dest, const T &val)
	{
		if (last < end_ptr)
		{
			copy_backward(dest + 1, last, last + 1);
			*dest = val;
			++last;
			return dest;
		}
		else
		{
			int n = dest - first;
			int size_cur = length();
			int resize = length() > 0 ? 2*length() : 1;
			T* target = static_cast<T*>(operator new(resize*sizeof(T)));
			T* temp = target;
			T* ret_first = first;
			while(ret_first != last)
			{
				new(temp) int(*first);
				++ret_first;
				++temp;
			}
			destroy();
			first = target;
			last = first + size_cur;
			end_ptr = first + resize;
			dest = first + n;
			copy_backward(dest + 1 , last, last + 1);
			*dest = val;
			++last;
			return dest;
		}
	}

	T* erase(T* dest)
	{
		copy(dest + 1, last, dest);
		(--last)->~T();
	}

	T& operator[](int index)
	{
		return *(first + index);
	}

	const T& operator[](int index) const
	{
		return *(first + index);
	}
	
private:
	T* copy_backward(T* head, T* tail, T* result)
	{
		if (head > tail)
		{
			return NULL;
		}
		while(tail != head)
		{
			*(--result) = *(--tail);
		}
		return result;
	}

	T* copy(T* head, T* tail, T* result)
	{
		while(head != tail)
		{
			*result = *head;
			++result;
			++head;
		}
	}

	void init(int size)
	{
		T* temp = static_cast<T*>(operator new(size*sizeof(T)));
		first = temp;
		last = first;
		end_ptr = first + size; 
	}

	void destroy()
	{
		while(last != first)
		{
			(--last)->~T();
		}
		operator delete(static_cast<void*>(first));
	}

	T*    first;
	T*    last;
	T*    end_ptr;
};

#endif