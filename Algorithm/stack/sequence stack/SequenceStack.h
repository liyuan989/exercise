#ifndef __SEQUENCESTACK_H__
#define __SEQUENCESTACK_H__

#ifndef NULL
#define NULL 0
#endif

template<typename T>
class SequenceStack
{
public:
	typedef T        value_type;

	SequenceStack()
		: first_ptr(NULL), last_ptr(NULL), end_ptr(NULL)
	{
	}

	~SequenceStack()
	{
		destroy();
	}

	bool empty() const
	{
		return first_ptr == last_ptr;
	}

	T& top()
	{
		T *ret = last_ptr;
		return *(--ret);
	}

	const T& top() const
	{
		T *ret = last_ptr;
		return *(--ret);
	}

	int size() const
	{
		return last_ptr - first_ptr;
	}

	void push(const T &val)
	{
		if (last_ptr ==  end_ptr)
		{
			int cur_size = size();
			int reserve_size = cur_size > 0 ? 2*size() : 1;
			T *target = static_cast<T*>(operator new(reserve_size*sizeof(T)));
			T *first_ptr_temp = first_ptr;
			T *target_temp = target;
			while (first_ptr_temp != last_ptr)
			{
				*target_temp = *first_ptr_temp;
				++target_temp;
				++first_ptr_temp;
			}
			destroy();
			first_ptr = target;
			last_ptr = first_ptr + cur_size;
			end_ptr = first_ptr + reserve_size;
			*last_ptr = val;
			++last_ptr;
		}
		else if (last_ptr < end_ptr)
		{
			*last_ptr = val;
			++last_ptr;
		}
		else
		{
		}
	}

	void pop()
	{
		last_ptr->~T();
		--last_ptr;
	}

private:
	void destroy()
	{
		while (last_ptr != first_ptr)
		{
			(--last_ptr)->~T();
		}
		operator delete(static_cast<void*>(first_ptr));
	}

	T*    first_ptr;
	T*    last_ptr;
	T*    end_ptr;
};

#endif