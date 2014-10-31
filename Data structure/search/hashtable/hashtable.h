#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#ifndef NULL
#define NULL 0
#endif

#include <vector>
#include <iostream>

class hash
{
public:
	int operator()(int key) const
	{
		return key % 7;
	}
};

template<typename T, typename Hash = hash>
class hashtable
{
public:
	enum
	{
		NULLKEY = -1 << (sizeof(T)*8 - 1)
	};

	typedef int 		(*hasher)(int);
	typedef T   		value_type;
	typedef T*			iterator;
	
	hashtable()
		: data_table(10, NULLKEY), table_size(10), count(0), hash_func()
	{
	}

	bool set_hash(int (*p)(int))
	{
		if (p)
		{
			hash_func = p;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool insert(const T& key)
	{
		if (count == table_size)
		{
			data_table.insert(data_table.end(), count, NULLKEY);
			table_size = 2 * count;
		}
		int index = hash_func(key);
		while (data_table[index] != NULLKEY)
		{
			index = hash_func(index + 1);
		}
		data_table[index] = key;
		++count;
		return true;
	}

	iterator find(const T& key)
	{
		int val = hash_func(key);
		if (data_table[val] != NULLKEY)
		{
			while (data_table[val] != key)
			{
				val = hash_func(val + 1);
				if (data_table[val] == NULLKEY)
				{
					return NULL;
				}
			}
			return &data_table[val];
		}
		else
		{
			return NULL;
		}
	}

	bool erase(const T& key)
	{
		int val = hash_func(key);
		if (data_table[val] != NULLKEY)
		{
			std::cout << data_table[val] << std::endl;
			while (data_table[val] != key)
			{
				val = hash_func(val + 1);
				if (data_table[val] == NULLKEY || val == hash_func(val + 1))
				{
					return false;
				}
			}
			data_table[val] = NULLKEY;
			--count;
			return true;
		}
		else
		{
			return false;
		}
	}

	int size() const
	{
		return count;
	}

	int max_size() const
	{
		return table_size;
	}

private:
	std::vector<T>    data_table;
	int 			  table_size;
	int 			  count;
	Hash   		  hash_func;
};

#endif