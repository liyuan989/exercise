#include <iostream>
#include <string>

template<typename T>
void merge_array(T* array, T* space, int dest, int index, int size)
{
	int i = dest;
	int j = index;
	int k = i;
	int last = dest + size;
	while (i < index && j < last)
	{
		if (array[i] < array[j])
		{
			space[k] = array[i];
			++i;
		}
		else
		{
			space[k] = array[j];
			++j;
		}
		++k;
	}
	if (i == index)
	{
		while (k < last)
		{
			space[k] = array[j];
			++k;
			++j;
		}
	}
	if (j == last)
	{
		while (k < last)
		{
			space[k] = array[i];
			++k;
			++i;
		}
	}
	for (int n = dest; n < last; ++n)
	{
		array[n] = space[n];
	}
}

template<typename T>
void do_merge_sort(T* array, T* space, int size, int k)
{
	int i;
	for (i = 0; i + 2 * k <= size; i += 2 * k)
	{
		int first = i;
		int index = first + k;
		merge_array(array, space, first , index, 2 * k);
	}
	if (i + k < size)
	{
		merge_array(array, space, i, i + k, size - i);
	}
}

template<typename T>
void merge_sort(T* array, int size)
{
	T* space = new T[size];
	memset(space, 0, sizeof(space));
	for (int k = 1; k <= size / 2; k *= 2)
	{
		do_merge_sort(array, space, size, k);
		if (2 * k > size / 2)
		{
			merge_array(array, space, 0, 2 * k, size);
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {3,2,1,6,7,5,13,10,12,11,4,9,8,17,19,20,16,23,14};
	merge_sort(a, 19);
	for (int i = 0; i < 19; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}