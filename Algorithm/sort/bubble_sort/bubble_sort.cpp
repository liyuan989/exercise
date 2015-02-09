#include <iostream>
#include <string>

template<typename T>
void bubble_sort(T* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = size - 2; j >= i; --j)
		{
			if (array[j] > array[j + 1])
			{
				T temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

template<typename T>
void buble_sort_optimized(T* array, int size)
{
	bool swap_data = true;
	for (int i = 0; i < size - 1 && swap_data; ++i)
	{
		swap_data = false;
		for (int j = size - 2; j >= i; --j)
		{
			if (array[j] > array[j + 1])
			{
				T temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap_data = true;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {3,2,1,6,7,5,4,9,8};
	bubble_sort(a, 9);
	for (int i = 0; i < 9; ++i)
	{
		std::cout << a[i];
	}
	std::cout << std::endl;
	int b[] = {3,2,1,6,7,5,4,9,8};
	buble_sort_optimized(b, 9);
	for (int i = 0; i < 9; ++i)
	{
		std::cout << b[i];
	}
	std::cout << std::endl;
	return 0;
}