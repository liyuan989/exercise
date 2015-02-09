#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

template<typename T, int MAXSIZE>
class circular_queue
{
public:
	typedef T        value_type;

	circular_queue()
		: head(0), rear(0)
	{
	}

	circular_queue(int size, const T &val)
		: head(0), rear(0)
	{
		if (size > 0 && size < MAXSIZE)
		{
			for (int i = 0; i != size; ++i)
			{
				space[i] = val;
			}
			rear = size;
		}
		else
		{
		}
	}

	bool empty() const
	{
		return head == rear;
	}

	int size() const
	{
		return (rear - head + MAXSIZE) % MAXSIZE;
	}

	T& front()
	{
		return space[head];
	}

	const T& front() const
	{
		return space[head];
	}

	void push(const T &val)
	{
		if ((rear + 1) % MAXSIZE == head)
		{
		}
		else
		{
			space[rear] = val;
			rear = (rear + 1) % MAXSIZE;
		}
	}

	void pop()
	{
		if (head == rear)
		{
		}
		else
		{
			head = (head + 1) % MAXSIZE;
		}
	}

private:
	T     space[MAXSIZE];
	int   head;
	int   rear;
};

#endif