#include <iostream>
#include <string>

template<typename Iter, typename T>
int fibonacci_search_array(Iter dest, int n, const T& key)
{
	int fibocacci_array[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
	int low = 0;
	int high = n - 1;
	int k = 0;
	while (n - 1 > fibocacci_array[k])
	{
		++k;
	}
	for (int i = high; i < fibocacci_array[k]; ++i)
	{
		dest[i] = dest[high];
	}
	while (low <= high)
	{
		int mid = low + fibocacci_array[k - 1];
		if (key < dest[mid])
		{
			high = mid - 1;
			k = k - 1;
		}
		else if (key > dest[mid])
		{
			low = mid + 1;
		}
		else
		{
			if (mid <= n - 1)
			{
				return mid;
			}
			else
			{
				return n - 1;
			}
		}
	}
}

template<typename Iter, typename T>
Iter fibonacci_search_pointer (Iter fisrt, Iter end, const T& key)
{
	int fibocacci_array[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
	int low = 0;
	int high = end - fisrt - 1;
	int k = 0;
	while (high > fibocacci_array[k])
	{
		++k;
	}
	for (int i = high; i < fibocacci_array[k]; ++i)
	{
		*(fisrt + i) = *(fisrt + high);
	}
	while (low <= high)
	{
		int mid = low + fibocacci_array[k - 1];
		if (key < *(fisrt + mid))
		{
			high = mid - 1;
			k = k - 1;
		}
		else if (key > *(fisrt + mid))
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			if (mid <= high)
			{
				return fisrt + mid;
			}
			else
			{
				return fisrt + high;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {0,1,16,24,35,47,59,62,73,88,99,0,0,0};
	int p1 = fibonacci_search_array(a, 11, 59);
	std::cout << "a[" << p1 << "] = " << a[p1] << std::endl;
	int *p2 = fibonacci_search_pointer(a, a + 11, 59);
	std::cout << "p2 = " << p2 << "  *p2 = " << *p2 << std::endl;
	return 0;
}