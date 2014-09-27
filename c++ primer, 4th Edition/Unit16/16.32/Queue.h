#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

template<typename T> 
class Queue;

template<typename T>
std::ostream& operator<<(std::ostream &os, const Queue<T> &obj);

template<typename T>
std::istream& operator>>(std::istream &in, Queue<T> &obj);

template<typename T> 
class QueueItem
{
	friend class Queue<T>;
	friend std::ostream& operator<< <T>(std::ostream &os, const Queue<T> &obj);
	friend std::istream& operator>> <T>(std::istream &in, Queue<T> &obj);
	QueueItem(const T &element)
		: item(element), next(0) { }
	T 		   item;
	QueueItem *next;
};

template<typename T> 
class Queue
{
public:
	friend std::ostream& operator<< <T>(std::ostream &os, const Queue<T> &obj);
	friend std::istream& operator>> <T>(std::istream &in, Queue<T> &obj);

	Queue()
		: head(0), tail(0) { }

	Queue(const Queue &_obj)
		: head(0), tail(0)
	{
		copy_element(_obj);
	}

	template<typename Interator>
	Queue(Interator beg, Interator end)
		: head(0), tail(0)
	{
		copy_element(beg, end);
	}

	~Queue()
	{
		destroy();
	}

	Queue& operator=(const Queue &elem)
	{
		if (!empty())
		{
			destroy();
			copy_element(elem);
		}
		return *this;
	}

	bool empty() const
	{
		return head == 0;
	}

	T& front()
	{
		return head->item;
	}

	const T& front() const
	{
		return head->item;
	}

	void push(const T &val)
	{
		QueueItem<T> *push_element = new QueueItem<T>(val);
		if (empty())
		{
			tail = push_element;
			head = tail;
		}
		else
		{
			tail->next = push_element;
			tail = push_element;
		}
	}

	void pop()
	{
		if (!empty())
		{
			QueueItem<T> *p_middle = head;
			head = head->next;
			delete p_middle;
		}
	}

	template<typename Interator>
	Queue& assign(Interator beg, Interator end)
	{
		destroy();
		copy_element(beg, end);
	}

private:
	void destroy()
	{
		while (!empty())
			pop();
	}

	template<typename Interator>
	void copy_element(Interator beg, Interator end)
	{
		while (beg != end)
		{
			push(*beg);
			++beg;
		}
	}

	QueueItem<T> *head;
	QueueItem<T> *tail;
};

template<typename T> 
std::ostream& operator<<(std::ostream &os, const Queue<T> &obj)
{
	for (QueueItem<T> *p = obj.head; p; p = p->next)
	{
		std::cout << "<" << p->item << ">" << std::endl;
	}
}

template<typename T>
std::istream& operator>>(std::istream &in, Queue<T> &obj)
{
	T mid;
	while (in >> mid)
	{
		obj.push(mid);
	}
}

#endif