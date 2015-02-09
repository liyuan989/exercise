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
void do_merge_sort(T* array, T* space, int dest, int size)
{
	if (size > 1)
	{
		int index = dest + size / 2;
		int size1 = index - dest;
		int size2 = dest + size - index;
		do_merge_sort(array, space, dest, size1);
		do_merge_sort(array, space, index, size2);
		merge_array(array, space, dest, index, size);
	}
}

template<typename T>
void merge_sort(T* array, int size)
{
	T* space = new T[size];
	do_merge_sort(array, space, 0, size);
	delete [] space;
}

int main(int argc, char const *argv[])
{
	int a[] = {3,2,1,6,7,5,13,10,12,11,4,9,8};
	merge_sort(a, 13);
	for (int i = 0; i < 13; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}