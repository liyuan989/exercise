#ifndef __STATICLIST_H__
#define __STATICLIST_H__

#ifndef NULL
#define NULL 0
#endif

template<typename T, int maxsize>
class StaticList
{
private:
	struct base
	{
		T    data;
		int  cur;
	};

public:
	StaticList(int size, const T &val)
	{
		for (int i = 0; i != maxsize; ++i)
		{
			space[i].cur = i + 1;
		}
		space[maxsize - 1].cur = 0;
		if (size <= maxsize - 1 && size > 0)
		{
			for (int i = 1; i <= size; ++i)
			{
				space[i].data = val;
			}
			space[size].cur = 0;
			space[0].cur = size + 1;
			space[maxsize - 1].cur = 1;
		}
		else
		{
		}	
	}

	bool empty() const
	{
		return space[0].cur == 1;
	}

	int size() const
	{
		int n = 0;
		for (base temp = space[1]; temp.cur != space[0].cur; temp = space[temp.cur])
		{
			++n;
		}
		return n;
	}

	int insert(int dest, const T &val)
	{
		if (size() < maxsize - 1)
		{
			int dest_cur = space[0].cur;
			space[dest_cur].data = val;
			space[dest_cur].cur = space[dest].cur;
			space[dest].cur = dest_cur;
			space[0].cur = dest_cur + 1;
			return dest_cur;
		}
		else
		{
		}
	}

	int erase(int dest)
	{
		int target = space[dest].cur;
		space[dest].cur = space[space[dest].cur].cur;
		space[target].cur = space[0].cur;
		space[0].cur = target;
	}

	T& operator[](int index)
	{
		int temp = maxsize - 1;
		for (int i = 0; i != index; ++i)
		{
			temp = space[temp].cur;
		}
		return space[temp].data;
	}

	const T& operator[](int index) const
	{
		int temp = maxsize - 1;
		for (int i = 0; i != index; ++i)
		{
			temp = space[temp].cur;
		}
		return space[temp].data;
	}

public:
	typedef T    value_type;
	
private:
	base space[maxsize];
};

#endif