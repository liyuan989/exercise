#include <iostream>
#include <string>

template<typename T>
void shell_sort(T* array, int size)
{
	for (int increment = size / 3 + 1; increment > 0; increment /= 3)
	{
		for (int i = 0; i + increment < size; ++i)
		{
			if (array[i + increment] < array[i])
			{
				T temp = array[i + increment];
				int j = -1;
				for (j = i; temp < array[j] && j >= 0; j -= increment)
				{
					array[j + increment] = array[j];
				}
				array[j + increment] = temp;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {3,2,1,6,7,5,13,10,12,11,4,9,8};
	shell_sort(a, 13);
	for (int i = 0; i < 13; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}