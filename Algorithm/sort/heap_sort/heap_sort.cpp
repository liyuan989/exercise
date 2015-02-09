#include <iostream>
#include <string>

template<typename T>
void adjust_heap(T* array, int index, int size)
{
	for (int i = index * 2; i < size; i *= 2)
	{
		if (array[i] < array[i + 1])
		{
			++i;
		}
		if (array[index] > array[i])
		{
			break;
		}
		T temp = array[index];
		array[index] = array[i];
		array[i] = temp;
		index = i;
	}
}

template<typename T>
void heap_sort(T* array, int size)
{
	for (int i = size / 2; i > 0; --i)
	{
		adjust_heap(array, i, size);
	}
	for (int j = size; j > 1; --j)
	{
		T temp = array[j];
		array[j] = array[1];
		array[1] = temp;
		adjust_heap(array, 1, j - 1);
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {0,3,2,1,6,7,5,13,10,12,11,4,9,8};
	heap_sort(a, 13);
	for (int i = 0; i < 14; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}