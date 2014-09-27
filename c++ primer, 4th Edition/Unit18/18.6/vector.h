/***********************************************************************
vector.h
author:Li Yuan
***********************************************************************/

#ifndef __VECTOR_H__
#define __VECTOR_H__

#ifndef NULL
#define NULL 0
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

typedef unsigned int size_t;

namespace ly
{

/***********************************************************************
allocator
***********************************************************************/

	template<typename T>
	class allocator
	{
	public:
		typedef T*              pointer;
		typedef const T*        const_pointer;
		typedef T&              reference;
		typedef const T&        const_reference;
		typedef T               value_type;
		typedef size_t          size_type;

		allocator()
		{
		}

		pointer address(reference x) const
		{
			return &x;
		}

		const_pointer address(const_reference x)
		{
			return &x;
		}

		pointer allocate(size_type n)
		{
			pointer p = static_cast<pointer>(operator new(n*sizeof(value_type)));
			return p;
		}

		void deallocate(pointer p, size_type n)
		{
			operator delete(static_cast<void*>(p));
		}

		size_type max_size() const
		{
			return -1;
		}

		void construct(pointer p, const_reference val)
		{
			new (p) value_type(val);
		}

		void destroy(pointer p)
		{
			p->~value_type();
		}
	};

/***********************************************************************
normal_iterator_base
***********************************************************************/

	template<typename T>
	class normal_iterator_base
	{
	public:
		typedef T      value_type;
		typedef size_t difference_type;

		normal_iterator_base()
			: pointer(NULL)
		{
		}

		normal_iterator_base(T *p)
			: pointer(p)
		{
		}

		T& operator*()
		{
			return *pointer;
		}

		const T& operator*() const
		{
			return *pointer;
		}

		T* operator->()
		{
			return pointer;
		}

		const T* operator->() const
		{
			return pointer;
		}

		normal_iterator_base& operator++()
		{
			++pointer;
			return *this;
		}

		normal_iterator_base operator++(int)
		{
			normal_iterator_base ret = *this;
			++pointer;
			return ret;
		}

		normal_iterator_base& operator--()
		{
			--pointer;
			return *this;
		}

		normal_iterator_base operator--(int)
		{
			normal_iterator_base ret = *this;
			--pointer;
			return ret;
		}

		bool operator!() const
		{
			if (!pointer)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		friend normal_iterator_base operator+(const normal_iterator_base &obj, 
		                                      difference_type n)
		{
			return normal_iterator_base(obj.pointer + n);
		}

		friend normal_iterator_base operator-(const normal_iterator_base &obj, 
		                                      difference_type n)
		{
			return normal_iterator_base(obj.pointer - n);
		}

		friend difference_type operator-(const normal_iterator_base &lhs,
		                                 const normal_iterator_base &rhs)
		{
			return lhs.pointer - rhs.pointer;
		}

		friend normal_iterator_base& operator+=(const normal_iterator_base &obj, 
		                                        difference_type n)
		{
			obj = obj + n;
			return obj;
		}

		friend normal_iterator_base& operator-=(const normal_iterator_base &obj, 
		                                        difference_type n)
		{
			obj = obj - n;
			return obj;
		}

		friend bool operator==(const normal_iterator_base &lhs, const normal_iterator_base &rhs)
		{
			return lhs.pointer == rhs.pointer;
		}

		friend bool operator!=(const normal_iterator_base &lhs, const normal_iterator_base &rhs)
		{
			return !(lhs == rhs);
		}

		friend bool operator<(const normal_iterator_base &lhs, const normal_iterator_base &rhs)
		{
			return lhs.pointer < rhs.pointer;
		}

		friend bool operator>(const normal_iterator_base &lhs, const normal_iterator_base &rhs)
		{
			return lhs.pointer > rhs.pointer;
		}

		friend bool operator<=(const normal_iterator_base &lhs, const normal_iterator_base &rhs)
		{
			return !(lhs > rhs);
		}

		friend bool operator>=(const normal_iterator_base &lhs, const normal_iterator_base &rhs)
		{
			return !(lhs < rhs);
		}

	private:
		T *pointer;
	};

/***********************************************************************
reverse_iterator_base
***********************************************************************/

	template<typename T>
	class reverse_iterator_base
	{
	public:
		typedef T        value_type;
		typedef size_t   difference_type;

		reverse_iterator_base()
			: pointer(NULL)
		{
		}

		reverse_iterator_base(T *p)
			: pointer(p)
		{
		}

		T& operator*()
		{
			return *pointer;
		}

		const T& operator*() const
		{
			return *pointer;
		}

		T* operator->()
		{
			return pointer;
		}

		const T* operator->() const
		{
			return pointer;
		}

		reverse_iterator_base& operator++()
		{
			--pointer;
			return *this;
		}

		reverse_iterator_base operator++(int)
		{
			reverse_iterator_base ret = *this;
			--pointer;
			return ret;
		}

		reverse_iterator_base& operator--()
		{
			++pointer;
			return *this;
		}

		reverse_iterator_base operator--(int)
		{
			reverse_iterator_base ret = *this;
			++pointer;
			return ret;
		}

		bool operator!() const
		{
			if (!pointer)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		friend reverse_iterator_base operator+(const reverse_iterator_base &obj, 
		                                       difference_type n)
		{
			return reverse_iterator_base(obj.pointer - n);
		}

		friend reverse_iterator_base operator-(const reverse_iterator_base &obj, 
		                                       difference_type n)
		{
			return reverse_iterator_base(obj.pointer + n);
		}

		friend reverse_iterator_base& operator-(const reverse_iterator_base &lhs, 
		                                        const reverse_iterator_base &rhs)
		{
			return lhs.pointer - rhs.pointer;
		}

		friend reverse_iterator_base& operator+=(const reverse_iterator_base &obj, 
		                                         difference_type n)
		{
			obj = obj - n;
			return obj;
		}

		friend reverse_iterator_base& operator-=(const reverse_iterator_base &obj, 
		                                         difference_type n)
		{
			obj = obj + n;
			return obj;
		}

		friend bool operator==(const reverse_iterator_base &lhs, const reverse_iterator_base &rhs)
		{
			return lhs.pointer == rhs.pointer;
		}

		friend bool operator!=(const reverse_iterator_base &lhs, const reverse_iterator_base &rhs)
		{
			return !(lhs == rhs);
		}

		friend bool operator<(const reverse_iterator_base &lhs, const reverse_iterator_base &rhs)
		{
			return lhs.pointer > rhs.pointer;
		}

		friend bool operator>(const reverse_iterator_base &lhs, const reverse_iterator_base &rhs)
		{
			return lhs.pointer < rhs.pointer;
		}

		friend bool operator<=(const reverse_iterator_base &lhs, const reverse_iterator_base &rhs)
		{
			return !(lhs > rhs);
		}

		friend bool operator>=(const reverse_iterator_base &lhs, const reverse_iterator_base &rhs)
		{
			return !(lhs < rhs);
		}

	private:
		T *pointer;
	};

/***********************************************************************
some algorithm function
***********************************************************************/

	template<typename Iterator>
	Iterator uninitialized_copy(Iterator first, Iterator last, Iterator result)
	{
		while (first != last)
		{
			new(static_cast<void*>(&*result)) typename Iterator::value_type(*first);
			++first;
			++result;
		}
		return result;
	}

	template<typename Iterator>
	int* uninitialized_copy(Iterator *first, Iterator *last, Iterator *result)
	{
		while(first != last)
		{
			new(result) int(*first);
			++first;
			++result;
		}
		return result;
	}

	template<typename Iterator, typename T>
	void uninitialized_fill(Iterator first, Iterator last, const T &val)
	{
		while (first != last)
		{
			new(static_cast<void*>(first)) typename Iterator::value_type(val);
			++first;
		}
	}

	template<typename Iterator, typename T>
	void uninitialized_fill(Iterator *first, Iterator *last, const T &val)
	{
		while(first != last)
		{
			new(first) int(val);
			++first;
		}
	}

	template<typename Iterator>
	Iterator copy_backward(Iterator first, Iterator last, Iterator result)
	{
		while (last != first)
		{
			*(--result) = *(--last);
		}
		return result;
	}

	template<typename Iterator>
	Iterator copy(Iterator first, Iterator last, Iterator result)
	{
		while(first != last)
		{
			*result = *first;
			++first;
			++result;
		}
	}

/***********************************************************************
vector
***********************************************************************/

	template<typename T, typename Alloc = allocator<T> >
	class vector
	{
	public:	
		typedef normal_iterator_base<T>            iterator;
		typedef const normal_iterator_base<T>      const_iterator;
		typedef reverse_iterator_base<T>           reverse_iterator;
		typedef const reverse_iterator_base<T>     const_reverse_iterator;
		typedef T                                  value_type;
		typedef T&                                 reference;
		typedef const T&                           const_reference;
		typedef size_t                             size_type;

		vector()
			: first_iter(NULL), last_iter(NULL), end_iter(NULL)
		{
		}

		vector(size_type n, const value_type &val)
			: first_iter(NULL), last_iter(NULL), end_iter(NULL)
		{
			first_iter = alloc.allocate(n);
			last_iter = first_iter + n;
			end_iter = last_iter;
			uninitialized_fill(&*first_iter, &*last_iter, val);	
		}

		vector(const vector &obj)
			: first_iter(NULL), last_iter(NULL), end_iter(NULL)
		{
			iterator copy_new_alloc = alloc.allocate(obj.size());
			uninitialized_copy(&*obj.first_iter, &*obj.last_iter, &*copy_new_alloc);
			first_iter = copy_new_alloc;
			last_iter = first_iter + obj.size();
			end_iter = last_iter;
		}

		vector(iterator first, iterator last)
			: first_iter(NULL), last_iter(NULL), end_iter(NULL)
		{
			size_type my_size = last - first;
			first_iter = alloc.allocate(my_size);
			uninitialized_copy(&*first, &*last, &*first_iter);
			last_iter = first_iter + my_size;
			end_iter = last_iter;
		}

		~vector()
		{
			for (iterator p = last_iter; p != first_iter; )
			{
				alloc.destroy(&*--p);
			}
			alloc.deallocate(&*first_iter, &*end_iter - &*first_iter);
		}

		size_type size() const
		{
			if (!end_iter)
			{
				return 0;
			}
			else
			{
				return last_iter - first_iter;
			}
		}

		size_type max_size() const
		{
			return size_type(-1);
		}

		bool empty() const
		{
			return !size();
		}

		void push_back(const value_type &val)
		{
			if (last_iter == end_iter)
			{
				reallocator();
			}
			alloc.construct(&*last_iter, val);
			++last_iter;
		}

		void pop_back()
		{
			alloc.destroy(&*--last_iter);
		}

		iterator begin()
		{
			return first_iter;
		}

		const_iterator begin() const
		{
			return first_iter;
		}

		iterator end()
		{
			return last_iter;
		}

		const_iterator end() const
		{
			return last_iter;
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(&*(last_iter - 1));
		}

		const_reverse_iterator rbegin() const
		{
			return reverse_iterator(&*(last_iter - 1));
		}

		reverse_iterator rend()
		{
			return reverse_iterator(&*(first_iter - 1));
		}

		const_reverse_iterator rend() const
		{
			return reverse_iterator(&*(first_iter - 1));
		}

		const_reference front()
		{
			return *first_iter;
		}

		const_reference front() const
		{
			return *first_iter;
		}

		reference back()
		{
			return *(last_iter - 1);
		}

		const_reference back() const
		{
			return *(last_iter - 1);
		}

		Alloc get_allocator() const
		{
			return alloc;
		}

		void clear()
		{
			if (size())
			{
				for (iterator p = last_iter; p != first_iter; )
				{
					alloc.destroy(&*--p);
				}
			}
		}

		size_type capacity() const
		{
			return end_iter - first_iter;
		}

		void reserve(size_type n)
		{
			iterator reserve_ptr = alloc.allocate(n);
			size_type leng = size();
			uninitialized_copy(&*first_iter, &*last_iter, &*reserve_ptr);
			for (iterator p = last_iter; p != first_iter; )
			{
				alloc.destroy(&*--p);
			}
			alloc.deallocate(&*first_iter, end_iter - first_iter);
			first_iter = reserve_ptr;
			last_iter = first_iter + leng;
			end_iter = first_iter + n;
		}

		void resize(size_type n)
		{
			if (n < size())
			{
				iterator p = last_iter;
				while (p != last_iter - (n - size()))
				{
					alloc.destroy(&*--p);
				}
				last_iter = p;
			}
			else
			{
				size_type leng = size();
				if (n <= capacity())
				{
					uninitialized_fill(&*last_iter, &*(last_iter + (n - size())), value_type());
					last_iter = last_iter + (n - size());
				}
				else
				{
					reserve(n);
					iterator mid_ptr = last_iter;
					while (mid_ptr != end_iter)
					{
						push_back(value_type());
						++mid_ptr;
					}
					last_iter = mid_ptr;
				}
			}
		}

		void resize(size_type n, const value_type &val)
		{
			if (n < size())
			{
				iterator p = last_iter;
				while (p != last_iter - (n - size()))
				{
					alloc.destroy(&*--p);
				}
				last_iter = p;
			}
			else
			{
				size_type leng = size();
				if (n <= capacity())
				{
					uninitialized_fill(&*last_iter, &*(last_iter + (n - size())), val);
					last_iter = last_iter + (n - size());
				}
				else
				{
					reserve(n);
					iterator mid_ptr = last_iter;
					while (mid_ptr != end_iter)
					{
						push_back(val);
						++mid_ptr;
					}
					last_iter = mid_ptr;
				}
			}
		}

		void assign(size_type n, const value_type &val)
		{
			for (iterator p = last_iter; p != first_iter; )
			{
				alloc.destroy(&*--p);
			}
			if (n <= capacity())
			{
				last_iter = first_iter + n;
				uninitialized_fill(&*first_iter, &*last_iter, val);
			}
			else
			{
				alloc.deallocate(&*first_iter, capacity());
				first_iter = alloc.allocate(n);
				last_iter = first_iter + n;
				end_iter = last_iter;
				uninitialized_fill(&*first_iter, &*last_iter, val);
			}
		}

		void assign(iterator first, iterator last)
		{
			size_type n = last - first;
			for (iterator p = last_iter; p != first_iter; )
			{
				alloc.destroy(&*--p);
			}
			if (n <= capacity())
			{
				uninitialized_copy(&*first, &*last, &*first_iter);
				last_iter = first_iter + n;
			}
			else
			{
				alloc.deallocate(&*first_iter, capacity());
				first_iter = alloc.allocate(n);
				last_iter = first_iter + n;
				end_iter = last_iter;
				uninitialized_copy(&*first, &*last, &*first_iter);
			}
		}

		void swap(vector &obj)
		{
			vector ret(*this);
			size_type leng_own = capacity();
			size_type leng_obj = obj.capacity();
			*this = obj;
			reserve(leng_obj);
			obj = ret;
			obj.reserve(leng_own);
		}

		iterator insert(iterator position, const value_type &val)
		{
			size_type num = position - first_iter;
			insert(position, 1, val);
			return first_iter + num;
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			if (position == last_iter)
			{
				for (size_type count = 0; count != n; ++count)
				{
					push_back(val);
				}

			}
			else
			{
				size_type num = position - first_iter;
				if (last_iter == end_iter)
				{
					reallocator();
				}
				position = first_iter + num;				
				copy_backward(&*position, &*last_iter, &*(last_iter + n));
				iterator it = position;
				for (size_type count = 0; count != n; ++count, ++it)
				{
					*it = val;
				}
				last_iter = last_iter + n;
			}
		}

		void insert(iterator position, iterator first, iterator last)
		{
			size_type distance = last - first;
			if (position == last_iter)
			{
				while (first != last)
				{
					push_back(*first);
					++first;
				}
			}
			else
			{
				size_type num = position - first_iter;
				if (last_iter == end_iter)
				{
					reallocator();
				}
				position = first_iter + num;
				copy_backward(&*position, &*last_iter, &*(last_iter + distance));
				iterator it = position;
				while (first != last)
				{
					*it = *first;
					++it;
					++first;
				}
				last_iter = last_iter + distance;
			}
		}

		iterator erase(iterator position)
		{
			return erase(position, position + 1);
		}

		iterator erase(iterator first, iterator last)
		{
			value_type distance = last - first;
			if (last == last_iter)
			{
				while(last != first)
				{
					pop_back();
					--last;
				}
			}
			else
			{
				copy(&*last, &*last_iter, &*first);
				iterator p = last_iter;
				for (int i = 0; i < distance; ++i)
				{
					alloc.destroy(&*--p);
				}
				last_iter = last_iter - distance;
			}
			return first;
		}

		reference at(size_type index)
		{
			return *(first_iter + index);
		}

		const_reference at(size_type index) const
		{
			return *(first_iter + index);
		}

		reference operator[](size_type index)
		{
			return *(first_iter + index);
		}

		const_reference operator[](size_type index) const
		{
			return *(first_iter + index);
		}

		vector& operator=(const vector &obj)
		{
			if (first_iter == obj.first_iter || end_iter == obj.end_iter)
			{
				return *this;
			}
			iterator assignment_alooc = alloc.allocate(obj.size());
			uninitialized_copy(&*obj.first_iter, &*obj.last_iter, &*assignment_alooc);
			clear();
			alloc.deallocate(&*first_iter, end_iter - first_iter);
			first_iter = assignment_alooc;
			last_iter = first_iter + obj.size();
			end_iter = last_iter;
			return *this;
		}

	private:
		void reallocator()
		{
			size_type curr_size = size();
			typename iterator::difference_type capacity_size = curr_size >= 1 ? 2*curr_size : 1;
			iterator new_alloc = alloc.allocate(capacity_size);
			
			uninitialized_copy(&*first_iter, &*end_iter, &*new_alloc);
			for (iterator p = end_iter; p != first_iter; )
			{
				alloc.destroy(&*--p);
			}
			alloc.deallocate(&*first_iter, end_iter - first_iter);
			first_iter = new_alloc;
			last_iter = first_iter + curr_size;
			end_iter = first_iter + capacity_size;
		}

		Alloc 		 	alloc;
		iterator  		first_iter;
		iterator  		last_iter;
		iterator  		end_iter;
	};

/***********************************************************************
operator overloading for vector
***********************************************************************/

	template<typename T, typename Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
		{
			return false;
		}
		for (int i = 0; i != lhs.size(); ++i)
		{
			if (lhs[i] != rhs[i])
			{
				return false;
			}
		}
		return true;
	}

	template<typename T, typename Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template<typename T, typename Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() < rhs.size())
		{
			for (int i = 0; i != lhs.size(); ++i)
			{
				if (lhs[i] != rhs[i])
				{
					return lhs[i] < rhs[i];
				}
			}
			return true;
		}
		else
		{
			for (int i = 0; i != rhs.size(); ++i)
			{
				if (lhs[i] != rhs[i])
				{
					return lhs[i] < rhs[i];
				}
			}
			return false;
		}
	}

	template<typename T, typename Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() > rhs.size())
		{
			for (int i = 0; i != rhs.size(); ++i)
			{
				if (lhs[i] != rhs[i])
				{
					return lhs[i] > rhs[i];
				}
			}
			return true;
		}
		else
		{
			for (int i = 0; i != lhs.size(); ++i)
			{
				if (lhs[i] != rhs[i])
				{
					return lhs[i] > rhs[i];
				}
			}
			return false;
		}
	}

	template<typename T, typename Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs > rhs);
	}

	template<typename T, typename Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}
}

#endif