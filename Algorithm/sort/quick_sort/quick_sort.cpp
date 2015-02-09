#include <iostream>
#include <string>

template<typename T>
int partition(T* array, int low, int high)
{
	T compare_base = array[low];
	while (low < high)
	{
		if (array[low] == compare_base)
		{
			if (array[low] < array[high])
			{
				--high;
			}
			else
			{
				array[low] = array[high];
				array[high] = compare_base;
				++low;
			}
		}
		else
		{
			if (array[low] < array[high])
			{
				++low;
			}
			else
			{
				array[high] = array[low];
				array[low] = compare_base;
				--high;
			}
		}
	}
	return low;
}

template<typename T>
void do_quick_sort(T* array, int first, int last)
{
	if (last > first)
	{
		int mid = partition(array, first, last);
		do_quick_sort(array, first, mid - 1);
		do_quick_sort(array, mid + 1, last);
	}
}

template<typename T>
void quick_sort(T* array, int size)
{
	do_quick_sort(array, 0, size - 1);
}

int main(int argc, char const *argv[])
{
	int a[] = {3,2,1,6,7,5,13,10,12,11,4,9,8};
	quick_sort(a, 13);
	for (int i = 0; i < 13; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}