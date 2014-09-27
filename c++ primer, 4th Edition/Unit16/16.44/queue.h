#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <list>

template<typename T>
class queue;

template<typename T>
std::ostream& operator<<(std::ostream &os, const queue<T> &obj);

template<typename T>
std::istream& operator>>(std::istream &in, queue<T> &obj);

template<typename T>
class queue
{
public:
	friend std::ostream& operator<< <T>(std::ostream &os, const queue<T> &obj);
	friend std::istream& operator>> <T>(std::istream &in, queue<T> &obj);

	queue()
		: data() { }

	template<typename Interator>
	queue(Interator beg, Interator end)
		: data(beg, end) { }

	queue(const queue &element)
		: data(element) { }

	~queue() { }

	bool empty() const
	{
		return data.empty();
	}

	T& front() const
	{
		return data.front();
	}

	void push(const T &val)
	{
		data.push_back(val);
	}

	void pop()
	{
		data.pop_front();
	}

	template<typename Interator>
	queue& assign(Interator beg, Interator end)
	{
		data.assign(beg, end);
		return *this;
	}

private:
	std::list<T> data;
};

template<typename T>
std::ostream& operator<<(std::ostream &os, const queue<T> &obj)
{
	for (typename std::list<T>::const_iterator it = obj.data.begin(); it != obj.data.end(); ++it)
	{
		os << "<" << *it << ">" << std::endl;
	}
}

template<typename T>
std::istream& operator>>(std::istream &in, queue<T> &obj)
{
	T mid;
	while (in >> mid)
	{
		obj.data.push_back(mid);
	}
}

#endif