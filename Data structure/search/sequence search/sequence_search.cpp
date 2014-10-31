#include <iostream>
#include <string>

template<typename Iter, typename T>
Iter normal_search(Iter first, Iter end, const T& key)
{
	while (first != end)
	{
		if (*first == key)
		{
			return first;
		}
		++first;
	}
}

template<typename Iter, typename T>
Iter optimized_search(Iter first, Iter end, const T& key)
{
	*end = key;
	while(*first != key)
	{
		++first;
	}
	return first;   //if first equal to end, search failed
}

int main(int argc, char const *argv[])
{
	int a[] = {0,1,2,3,4,5};
	int* p1 = normal_search(a, a + 6, 10);
	if (p1 == a + 6)
	{
		std::cout << "search failed" << std::endl;
	}
	int* p2 = optimized_search(a, a + 6, 10);
	if (p2 == a + 6)
	{
		std::cout << "search failed" << std::endl;
	}
	return 0;
}