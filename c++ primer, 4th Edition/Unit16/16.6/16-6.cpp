#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
template <class Type>
class List
{
public:
	typedef std::bidirectional_iterator_tag iterator;
	typedef const std::bidirectional_iterator_tag const_iterator;
	typedef std::reverse_iterator<std::bidirectional_iterator_tag> reverse_iterator;
	List();
	List(List<Type>&);
	List(iterator&, iterator&);
	List(size_t&, Type = Type());
	~List();
	Type& front();
	Type& back();
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();
	void push_back(Type);
	void push_front(Type);
	iterator insert(iterator&, Type);
	void insert(iterator&, size_t&, Type);
	void insert(iterator&, iterator&, iterator&);
	bool empty();
	void resize(size_t&);
	void resize(size_t&, Type);
	iterator erase(iterator&);
	iterator erase(iterator&, iterator&);
	void clear();
	void pop_back();
	void pop_front();
	void swap(List<Type>&);
	void assign(iterator&, iterator&);
	void assign(size_t&, Type);
};

