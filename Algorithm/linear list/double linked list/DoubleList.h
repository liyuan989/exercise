#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__

#ifndef NULL
#define NULL 0
#endif

template<typename T>
class DoubleList
{
private:
	struct base
	{
		T      data;
		base*  prior;
		base*  next;
	};

public:
	typedef T        value_type;
	typedef base*    iterator;

	DoubleList()
		: head(new base), tail(head->next)
	{
	}

	explicit DoubleList(int size)
		: head(new base), tail(head->next)
	{
		base* temp = head;
		for (int i = 0; i < size; ++i)
		{
			temp->next = new base;
			temp->next->prior = temp;
			temp = temp->next;
		}
		temp->next = head;
		head->prior = temp;
		tail = temp->next;
	}

	DoubleList(int size, const T &val)
		: head(new base), tail(head->next)
	{
		base* temp = head;
		for (int i = 0; i < size; ++i)
		{
			temp->next = new base;
			temp->next->prior = temp;
			temp = temp->next;
			temp->data = val;
		}
		temp->next = head;
		head->prior = temp;
		tail = temp->next;
	}

	~DoubleList()
	{
		base *boundary = head;
		head = head->next;
		delete boundary;
		while(head != boundary)
		{
			base* temp = head;
			head = head->next;
			delete temp;
		}
	}

	bool empty() const
	{
		return head->next == head;
	}

	int size() const
	{
		int count = 0;
		for (base *temp = head->next; temp != tail; temp = temp->next)
		{
			++count;
		}
		return count;
	}

	iterator begin()
	{
		return head->next;
	}

	const iterator begin() const
	{
		return head->next;
	}

	iterator end()
	{
		return tail;
	}
	const iterator end() const
	{
		return tail;
	}

	iterator insert(iterator dest, const T &val)
	{
		base *target = new base;
		target->data = val;
		target->prior = dest->prior;
		dest->prior->next = target;
		target->next = dest;
		dest->prior = target;
	}

	iterator erase(iterator dest)
	{
		dest->prior->next = dest->next;
		dest->next->prior = dest->prior;
		delete dest;
	}

	T& operator[](int index)
	{
		base *temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		return temp->data;
	}

	const T& operator[](int index) const
	{
		base *temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		return temp->data;
	}

private:
	base*  head;
	base*  tail;	
};

#endif