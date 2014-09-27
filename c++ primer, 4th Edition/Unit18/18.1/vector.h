#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <algorithm>
#include <memory>

namespace ly
{
	template<typename T>
	class reverse_iterator_base
	{
	public:
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
			return --pointer;
		}

		reverse_iterator_base operator++(int)
		{
			T *ret = pointer;
			--pointer;
			return ret;
		}

		reverse_iterator_base& operator--()
		{
			return ++pointer;
		}

		reverse_iterator_base operator--(int)
		{
			T *ret = pointer;
			++pointer;
			return ret;
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

	template<typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:	
		typedef T* 	   							   iterator;
		typedef const T* 						   const_iterator;
		typedef reverse_iterator_base<T>    	   reverse_iterator;
		typedef const reverse_iterator_base<T> 	   const_reverse_iterator;
		typedef T      							   value_type;
		typedef T&								   reference;
		typedef const T&						   const_reference;
		typedef size_t 							   size_type;

		vector()
			: first_ptr(NULL), first_free_ptr(NULL), end_ptr(NULL)
		{
		}

		vector(size_type n, const value_type &val)
			: first_ptr(NULL), first_free_ptr(NULL), end_ptr(NULL)
		{
			first_ptr = alloc.allocate(n);
			first_free_ptr = first_ptr + n;
			end_ptr = first_free_ptr;
			std::uninitialized_fill(first_ptr, first_free_ptr, val);	
		}

		vector(const vector &obj)
			: first_ptr(NULL), first_free_ptr(NULL), end_ptr(NULL)
		{
			iterator copy_new_alloc = alloc.allocate(obj.size());
			std::uninitialized_copy(obj.first_ptr, obj.first_free_ptr, copy_new_alloc);
			first_ptr = copy_new_alloc;
			first_free_ptr = first_ptr + obj.size();
			end_ptr = first_free_ptr;
		}

		vector(iterator first, iterator last)
			: first_ptr(NULL), first_free_ptr(NULL), end_ptr(NULL)
		{
			size_type my_size = last - first;
			first_ptr = alloc.allocate(my_size);
			std::uninitialized_copy(first, last, first_ptr);
			first_free_ptr = first_ptr + my_size;
			end_ptr = first_free_ptr;
		}

		~vector()
		{
			for (iterator p = first_free_ptr; p != first_ptr; )
			{
				alloc.destroy(--p);
			}
			alloc.deallocate(first_ptr, end_ptr - first_ptr);
		}

		size_type size() const
		{
			if (!end_ptr)
			{
				return 0;
			}
			else
				return first_free_ptr - first_ptr;
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
			if (first_free_ptr == end_ptr)
			{
				reallocator();
			}
			alloc.construct(first_free_ptr, val);
			++first_free_ptr;
		}

		void pop_back()
		{
			alloc.destroy(--first_free_ptr);
		}

		iterator begin()
		{
			return first_ptr;
		}

		const_iterator begin() const
		{
			return first_ptr;
		}

		iterator end()
		{
			return first_free_ptr;
		}

		const_iterator end() const
		{
			return first_free_ptr;
		}

		reverse_iterator rbegin()
		{
			return first_free_ptr - 1;
		}

		const_reverse_iterator rbegin() const
		{
			return first_free_ptr - 1;
		}

		reverse_iterator rend()
		{
			return first_ptr - 1;
		}

		const_reverse_iterator rend() const
		{
			return first_ptr - 1;
		}

		const_reference front()
		{
			return *first_ptr;
		}

		const_reference front() const
		{
			return *first_ptr;
		}

		reference back()
		{
			return *(first_free_ptr - 1);
		}

		const_reference back() const
		{
			return *(first_free_ptr - 1);
		}

		Alloc get_allocator() const
		{
			return alloc;
		}

		void clear()
		{
			if (size())
			{
				for (iterator p = first_free_ptr; p != first_ptr; )
				{
					alloc.destroy(--p);
				}
			}
		}

		size_type capacity() const
		{
			return end_ptr - first_ptr;
		}

		void reserve(size_type n)
		{
			iterator reserve_ptr = alloc.allocate(n);
			size_type leng = size();
			std::uninitialized_copy(first_ptr, first_free_ptr, reserve_ptr);
			for (iterator p = first_free_ptr; p != first_ptr; )
			{
				alloc.destroy(--p);
			}
			alloc.deallocate(first_ptr, end_ptr - first_ptr);
			first_ptr = reserve_ptr;
			first_free_ptr = first_ptr + leng;
			end_ptr = first_ptr + n;
		}

		void resize(size_type n)
		{
			if (n < size())
			{
				iterator p = first_free_ptr;
				while (p != first_free_ptr - (n - size()))
				{
					alloc.destroy(--p);
				}
				first_free_ptr = p;
			}
			else
			{
				size_type leng = size();
				if (n <= capacity())
				{
					std::uninitialized_fill(first_free_ptr, first_free_ptr + (n - size()), value_type());
					first_free_ptr = first_free_ptr + (n - size());
				}
				else
				{
					reserve(n);
					iterator mid_ptr = first_free_ptr;
					while (mid_ptr != end_ptr)
					{
						push_back(value_type());
						++mid_ptr;
					}
					first_free_ptr = mid_ptr;
				}
			}
		}

		void resize(size_type n, const value_type &val)
		{
			if (n < size())
			{
				iterator p = first_free_ptr;
				while (p != first_free_ptr - (n - size()))
				{
					alloc.destroy(--p);
				}
				first_free_ptr = p;
			}
			else
			{
				size_type leng = size();
				if (n <= capacity())
				{
					std::uninitialized_fill(first_free_ptr, first_free_ptr + (n - size()), val);
					first_free_ptr = first_free_ptr + (n - size());
				}
				else
				{
					reserve(n);
					iterator mid_ptr = first_free_ptr;
					while (mid_ptr != end_ptr)
					{
						push_back(val);
						++mid_ptr;
					}
					first_free_ptr = mid_ptr;
				}
			}
		}

		void assign(size_type n, const value_type &val)
		{
			for (iterator p = first_free_ptr; p != first_ptr; )
			{
				alloc.destroy(--p);
			}
			if (n <= capacity())
			{
				first_free_ptr = first_ptr + n;
				std::uninitialized_fill(first_ptr, first_free_ptr, val);
			}
			else
			{
				alloc.deallocate(first_ptr, capacity());
				first_ptr = alloc.allocate(n);
				first_free_ptr = first_ptr + n;
				end_ptr = first_free_ptr;
				std::uninitialized_fill(first_ptr, first_free_ptr, val);
			}
		}

		void assign(iterator first, iterator last)
		{
			size_type n = last - first;
			for (iterator p = first_free_ptr; p != first_ptr; )
			{
				alloc.destroy(--p);
			}
			if (n <= capacity())
			{
				std::uninitialized_copy(first, last, first_ptr);
				first_free_ptr = first_ptr + n;
			}
			else
			{
				alloc.deallocate(first_ptr, capacity());
				first_ptr = alloc.allocate(n);
				first_free_ptr = first_ptr + n;
				end_ptr = first_free_ptr;
				std::uninitialized_copy(first, last, first_ptr);
			}
		}

		void swap(vector &obj)
		{
			std::swap(*this, obj);
		}

		iterator insert(iterator position, const value_type &val)
		{
			size_type num = position - first_ptr;
			insert(position, 1, val);
			return first_ptr + num;
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			if (position == first_free_ptr)
			{
				for (size_type count = 0; count != n; ++count)
				{
					push_back(val);
				}

			}
			else
			{
				size_type num = position - first_ptr;
				if (first_free_ptr == end_ptr)
				{
					reallocator();
				}
				position = first_ptr + num;				
				std::copy_backward(position, first_free_ptr, first_free_ptr + n);
				iterator it = position;
				for (size_type count = 0; count != n; ++count, ++it)
				{
					*it = val;
				}
				first_free_ptr = first_free_ptr + n;
			}
		}

		void insert(iterator position, iterator first, iterator last)
		{
			size_type distance = last - first;
			if (position == first_free_ptr)
			{
				while (first != last)
				{
					push_back(*first);
					++first;
				}
			}
			else
			{
				size_type num = position - first_ptr;
				if (first_free_ptr == end_ptr)
				{
					reallocator();
				}
				position = first_ptr + num;
				std::copy_backward(position, first_free_ptr, first_free_ptr + distance);
				iterator it = position;
				while (first != last)
				{
					*it = *first;
					++it;
					++first;
				}
				first_free_ptr = first_free_ptr + distance;
			}
		}

		iterator erase(iterator position)
		{
			return erase(position, position + 1);
		}

		iterator erase(iterator first, iterator last)
		{
			value_type distance = last - first;
			if (last == first_free_ptr)
			{
				while(last != first)
				{
					pop_back();
					--last;
				}
			}
			else
			{
				std::copy(last, first_free_ptr, first);
				iterator p = first_free_ptr;
				for (int i = 0; i < distance; ++i)
				{
					alloc.destroy(--p);
				}
				first_free_ptr = first_free_ptr - distance;
			}
			return first;
		}

		reference at(size_type index)
		{
			return *(first_ptr + index);
		}

		const_reference at(size_type index) const
		{
			return *(first_ptr + index);
		}

		reference operator[](size_type index)
		{
			return *(first_ptr + index);
		}

		const_reference operator[](size_type index) const
		{
			return *(first_ptr + index);
		}

		vector& operator=(const vector &obj)
		{
			if (first_ptr == obj.first_ptr || end_ptr == obj.end_ptr)
			{
				return *this;
			}
			iterator assignment_alooc = alloc.allocate(obj.size());
			std::uninitialized_copy(obj.first_ptr, obj.first_free_ptr, assignment_alooc);
			clear();
			alloc.deallocate(first_ptr, end_ptr - first_ptr);
			first_ptr = assignment_alooc;
			first_free_ptr = first_ptr + obj.size();
			end_ptr = first_free_ptr;
			return *this;
		}

	private:
		void reallocator()
		{
			size_type curr_size = size();
			std::ptrdiff_t capacity_size = curr_size >= 1 ? 2*curr_size : 1;
			iterator new_alloc = alloc.allocate(capacity_size);
			std::uninitialized_copy(first_ptr, end_ptr, new_alloc);
			for (iterator p = end_ptr; p != first_ptr; )
			{
				alloc.destroy(--p);
			}
			alloc.deallocate(first_ptr, end_ptr - first_ptr);
			first_ptr = new_alloc;
			first_free_ptr = first_ptr + curr_size;
			end_ptr = first_ptr + capacity_size;
		}

		Alloc 		 	alloc;
		iterator  		first_ptr;
		iterator  		first_free_ptr;
		iterator  		end_ptr;
	};

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