#ifndef __SHARED_STACK_H__
#define __SHARED_STACK_H__

#ifndef NULL
#define NULL 0
#endif

template<typename T, int MAXSIZE>
class shared_stack
{
public:
	typedef T        value_type;

	shared_stack()
		: top1(space - 1), top2(space + MAXSIZE)
	{
	}

	bool empty(int stack_number) const
	{
		if (stack_number == 1)
		{
			return top1 == space - 1;
		}
		if (stack_number == 2)
		{
			return top2 == space + MAXSIZE;
		}
	}

	int size(int stack_number) const
	{
		if (stack_number == 1)
		{
			return top1 - (space - 1);
		}
		if (stack_number == 2)
		{
			return space + MAXSIZE - top2;
		}
	}

	T& top(int stack_number)
	{
		if (stack_number == 1)
		{
			return *top1;
		}
		if (stack_number == 2)
		{
			return *top2;
		}
	}

	const T& top(int stack_number) const
	{
		if (stack_number == 1)
		{
			return *top1;
		}
		if (stack_number == 2)
		{
			return *top2;
		}
	}

	void push(const T &val, int stack_number)
	{
		if (stack_number == 1)
		{
			if (top1 + 1 >= top2)
			{
			}
			else
			{
				*++top1 = val;
			}
		}
		if (stack_number == 2)
		{
			if (top1 + 1 >= top2)
			{
			}
			else
			{
				*--top2 = val;
			}
		}
	}

	void pop(int stack_number)
	{
		if (stack_number == 1)
		{
			--top1;
		}
		if (stack_number == 2)
		{
			++top2;
		}
	}

private:
	T     space[MAXSIZE];
	T*    top1;
	T*    top2;
};


#endif