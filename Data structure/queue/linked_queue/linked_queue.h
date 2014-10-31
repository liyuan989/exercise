#ifndef __LINKED_QUEUE_H__
#define __LINKED_QUEUE_H__

#ifndef NULL
#define NULL 0
#endif

template<typename T>
class linked_queue
{
private:
	struct base
	{
		T      data;
		base*  next;
	};

public:
	typedef T        value_type;

	linked_queue()
		: head(new base), end(head)
	{
	}

	explicit linked_queue(int size)
		: head(new base), end(head)
	{
		base *temp = head;
		for (int i = 0; i < size; ++i)
		{
			temp->next = new base;
			temp = temp->next;
		}
		end = temp;
	}

	linked_queue(int size, const T &val)
		: head(new base), end(head)
	{
		base *temp = head;
		for (int i = 0; i < size; ++i)
		{
			temp->next = new base;
			temp = temp->next;
			temp->data = val;
		}
		end = temp;
	}

	~linked_queue()
	{
		while (head != end)
		{
			base *temp = head->next;
			delete head;
			head = temp;
		}
		delete end;
	}

	bool empty() const
	{
		return head == end;
	}

	int size() const
	{
		int count = 0;
		for (base *temp = head; temp != end; temp = temp->next)
		{
			++count;
		}
		return count;
	}

	T& front()
	{
		return head->next->data;
	}

	const T& front() const
	{
		return head->next->data;
	}

	void push(const T &val)
	{
		base *target = new base;
		target->data = val;
		end->next = target;
		end = target;
	}

	void pop()
	{
		if (head != end)
		{
			base *temp = head->next;
			head->next = head->next->next;
			delete temp;
		}
	}

private:
	base*    head;
	base*    end;
};

#endif