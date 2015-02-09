#include <iostream>
#include <string>

template<typename T>
void merge_array(T* space, T* array, int i, int index, int size) 
{
	int j;
	int k;
	int last = i + size;
	for (k = i, j = index; i < index && j < last ;++k)
	{
		if (space[i] < space[j])
		{
			array[k] = space[i];
			++i;
		}
		else
		{
			array[k] = space[j];
			++j;
		}
	}
	if (i == index)
	{
		while (k < last)
		{
			array[k] = space[j];
			++k;
			++j;
		}
	}
	if (j == last)
	{
		while (k < last)
		{
			array[k] = space[i];
			++k;
			++i;
		}
	}
}

template<typename T>
void do_merge_sort(T* array, T* widget, int dest, int size, int max_size)
{
	T* space = new T[max_size];
	memset(space, 0, sizeof(space));
	if (size <= 1)
	{
		widget[dest] = array[dest];
		return;
	}
	int index = dest + size / 2;
	int size1 = index - dest;
	int size2 = dest + size - index;
	do_merge_sort(array, space, dest, size1, max_size);
	do_merge_sort(array, space, index, size2, max_size);
	merge_array(space, widget, dest, index, size);
	delete [] space;
}

template<typename T>
void merge_sort(T* array, int size)
{
	do_merge_sort(array, array, 0, size, size);
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