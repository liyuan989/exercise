#include <iostream>
#include <string>

template<typename Iter, typename T>
Iter binary_search_pointer(Iter first, Iter last, const T& key)
{
	int low = 0;
	int high = last - first - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (key < *(first + mid))
		{
			high = mid - 1;
		}
		else if (key > *(first + mid))
		{
			low = mid + 1;
		}
		else
		{
			return first + mid;
		}
	}
}

template<typename Iter, typename T>
int binary_search_array(Iter dest, int n, const T& key)
{
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (key < dest[mid])
		{
			high = mid -1;
		}
		else if (key > dest[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {0,1,16,24,35,47,59,62,73,88,99};
	int *p1 = binary_search_pointer(a, a + 11, 62);
	std::cout << *p1 << std::endl;
	int p2 = binary_search_array(a, 11, 62);
	std::cout << a[p2] << std::endl;
	return 0;
}