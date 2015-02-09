#include <iostream>
#include <string>

template<typename T>
void insertion_sort(T* array, int size)
{
	for (int i = 1; i < size; ++i)
	{
		if (array[i] < array[i - 1])
		{
			int j = i;
			T temp = array[i];
			while (j >= 1 && temp < array[j - 1])
			{
				array[j] = array[j - 1];
				--j;
			}
			array[j] = temp;
		}
	}
}

template<typename T>
int partition(T* array, int low, int high)
{
	int mid = (low + high) / 2;
	if (array[low] > array[high])
	{
		T temp = array[low];
		array[low] = array[high];
		array[high] = temp;
	}
	if (array[mid] > array[high])
	{
		T temp = array[mid];
		array[mid] = array[high];
		array[high] = temp;
	}
	if (array[low] < array[mid])
	{
		T temp = array[low];
		array[low] = array[mid];
		array[mid] = temp;
	}
	T compare_base = array[low];
	while (low < high)
	{
		while (low < high && compare_base < array[high])
		{
			--high;
		}
		array[low] = array[high];
		while (low < high && compare_base > array[low])
		{
			++low;
		}
		array[high] = array[low];
	}
	array[low] = compare_base;
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
	if (size > 7)
	{
		do_quick_sort(array, 0, size - 1);
	}
	else
	{
		insertion_sort(array, size);
	}
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