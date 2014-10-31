#ifndef __CIRCULARLIST_H__
#define __CIRCULARLIST_H__

#ifndef NULL
#define NULL 0
#endif

template<typename T>
class CircularList
{
private:
	struct base
	{
		T     data;
		base* next;
	};

public:
	typedef T        value_type;
	typedef base*    iterator;

	CircularList()
		: head(new base), tail(head->next)
	{
	}

	explicit CircularList(int size)
		: head(new base), tail(head->next)
	{
		if (!size)
		{
		}
		else
		{
			base* temp = head;
			for (int i = 0; i != size; ++i)
			{
				temp->next = new base;
				temp = temp->next;
			}
			temp->next = head;
			tail = temp->next;
		}
	}

	CircularList(int size, const T &val)
		: head(new base), tail(head->next)
	{
		if (!size)
		{
		}
		else
		{
			base* temp = head;
			for (int i = 0; i != size; ++i)
			{
				temp->next = new base;
				temp = temp->next;
				temp->data = val;
			}
			temp->next = head;
			tail = temp->next;
		}
	}

	~CircularList()
	{
		while(head != tail)
		{
			base *temp = head->next;
			delete head;
			head = temp;
		}
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

	bool empty() const
	{
		return head->next == NULL;
	}

	int size() const
	{
		int count = 0;
		for (base *ret = head->next; ret != tail; ret = ret->next)
		{
			++count;
		}
		return count;
	}

	iterator insert(iterator dest, const T &val)
	{
		base* ret = new base;
		ret->data = val;
		ret->next = dest->next;
		dest->next = ret;
		return ret;
	}

	iterator erase(iterator dest)
	{
		base* temp = dest->next;
		dest->next = dest->next->next;
		delete temp;
	}

	T& operator[](int index)
	{
		base* ret = head->next;
		for (int i = 0; i != index; ++i)
		{
			ret = ret->next;
		}
		return ret->data;
	}

	const T& operator[](int index) const
	{
		base* ret = head->next;
		for (int i = 0; i != index; ++i)
		{
			ret = ret->next;
		}
		return ret->data;
	}

private:
	base* head;
	base* tail;
};

#endif