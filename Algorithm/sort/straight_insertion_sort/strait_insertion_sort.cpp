#include <iostream>
#include <string>

template<typename T>
void straight_inertion_sort(T* array, int size)
{
	for (int i = 1; i < size; ++i)
	{
		if (array[i] < array[i - 1])
		{
			T temp = array[i];
			int j = i;
			while (temp < array[j - 1] && j > 0)
			{
				array[j] = array[j - 1];
				--j;
			}
			array[j] = temp;
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {3,2,1,6,7,5,13,10,12,11,4,9,8};
	straight_inertion_sort(a, 13);
	for (int i = 0; i < 13; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}