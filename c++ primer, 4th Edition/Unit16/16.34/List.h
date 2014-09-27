#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>

template<typename T> 
class List;

template <typename T>
std::ostream& operator<<(std::ostream &os, const List<T> &obj);

template<typename T> 
class ListItem
{
private:
	friend class List<T>;
	friend std::ostream& operator<< <T> (std::ostream &os, const List<T> &obj);
	ListItem(const T &elem): previous(0), data(elem), next(0) { }
	ListItem *previous;
	T data;
	ListItem *next;
};

template<typename T> 
class List
{
public:
	friend std::ostream& operator<< <T> (std::ostream &os, const List<T> &obj);
	typedef T size_type;
	typedef ListItem<T>* pointer;

	List()
		: head(0), tail(0) { }

	template<typename Interator>
	List(Interator beg, Interator end)
		: head(0), tail(0)
	{
		copy_back_element(beg, end);
	}

	List(const List &obj)
		: head(0), tail(0) 
	{
		copy_back_element(obj);
	}

	List& operator=(const List &obj)
	{
		clear();
		copy_back_element(obj);
	}

	~List()
	{
		clear();
	}

	bool empty() const
	{
		return (tail == 0) && (head == 0);
	}

	T& back()
	{
		return tail->data;
	}

	const T& back() const 
	{
		return tail->data;
	}

	T& front()
	{
		return head->data;
	}

	const T& front() const
	{
		return head->data;
	}

	void push_back(const T val)
	{
		ListItem<T> *push_back_elem = new ListItem<T>(val);
		if (!empty())
		{
			tail->next = push_back_elem;
			push_back_elem->previous = tail;
			head->previous = push_back_elem;
			push_back_elem->next = head;
			tail = push_back_elem;
		}
		else
		{
			head = push_back_elem;
			tail = push_back_elem;
			tail->next = head;
			head->previous = tail;
		}
	}

	void push_front(const T val)
	{
		
		ListItem<T> *push_front_elem = new ListItem<T>(val);
		if (!empty())
		{
			head->previous = push_front_elem;
			push_front_elem->next = head;
			tail->next = push_front_elem;
			push_front_elem->previous = tail;
			head = push_front_elem; 			
		}
		else
		{
			head = push_front_elem;
			tail = push_front_elem;
			tail->next = head;
			head->previous = tail;
		}
	}

	void pop_back()
	{
		ListItem<T> *p = tail;
		if (tail->previous != tail)
		{
			tail = tail->previous;
			tail->next = head;
			head->previous = tail;
			delete p;
		}
		else
		{
			tail = 0;
			head = 0;
			delete p;
		}
	}

	void pop_front()
	{
		ListItem<T> *p = head;
		if (head->next != head)
		{
			head = head->next;
			head->previous = tail;
			tail->next = head;
			delete p;
		}
		else
		{
			tail = 0;
			head = 0;
			delete p;
		}
	}

	template<typename Interator>
	List& assign(Interator beg, Interator end)
	{
		clear();
		copy_back_element(beg, end);
	}

private:
	template<typename Iterator>
	void copy_back_element(Iterator beg, Iterator end)
	{
		while (beg != end)
		{
			push_back(*beg);
			++beg;
		}
	}

	template<typename Iterator>
	void copy_front_element(Iterator beg, Iterator end)
	{
		while (beg != end)
		{
			push_front(*beg);
		}
	}

	void clear()
	{
		while (!empty())
			pop_back();
	}

	ListItem<T> *head;
	ListItem<T> *tail;
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const List<T> &obj)
	{
		for (ListItem<T> *p = obj.head; p != obj.tail; p = p->next)
		{
			std::cout << "<" <<p->data << ">" << "\n";
		}
		std::cout << "<" << obj.tail->data << ">" << std::endl;
	}

#endif