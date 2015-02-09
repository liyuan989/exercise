#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_h__

#ifndef NULL
#define NULL 0
#endif

template<typename T>
class linked_stack
{
private:
	struct base
	{
		T      data;
		base*  next;
	};

public:
	typedef T        value_type;

	linked_stack()
		: top_ptr(NULL), count(0)
	{
	}

	~linked_stack()
	{
		while (!top_ptr)
		{
			pop();
		}
	}

	bool empty() const
	{
		return !count;
	}

	int size() const
	{
		return count;
	}

	T& top()
	{
		return top_ptr->data;
	}

	const T& top() const
	{
		return top_ptr->data;
	}

	void push(const T &val)
	{
		base *target = new base;
		target->data = val;
		if (!top_ptr)
		{
			target->next = NULL;
		}
		else
		{
			target->next = top_ptr;
		}
		top_ptr = target;
		++count;
	}

	void pop()
	{
		if (top_ptr)
		{
			base *temp = top_ptr;
			top_ptr = top_ptr->next;
			--count;
			delete temp;
		}
	}

private:
	base*    top_ptr;
	int      count;
};

#endif