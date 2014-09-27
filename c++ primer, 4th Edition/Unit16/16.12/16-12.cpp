#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

template <class InputIterator>
InputIterator MostFrequently(InputIterator first, InputIterator last)
{
	size_t count = 0;
	InputIterator max_it;
	while (first != last)
	{
		size_t n = std::count(first, last, *first);
		if (n > count)
		{
			count = n;
			max_it = first;
		}
		++first;
	}
	return max_it;
}

int main(int argc, char const *argv[])
{
	int array[] = {0,1,2,3,1,2,3,1};
	std::vector<int> ivec(array, array + 8);
	std::vector<int>::iterator it = MostFrequently(ivec.begin(), ivec.end());
	std::cout << *it << std::endl;
	return 0;
}