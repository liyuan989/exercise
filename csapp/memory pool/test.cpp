#include <iostream>
#include "MemoryPool.h"

int main(int argc, char const *argv[])
{
	if (mm_init() == -1)
	{
		std::cout << "mm_init failed!" << std::endl;
	}
	int size = 1040000;
	int* p = static_cast<int*>(mm_malloc(size * sizeof(int)));
	for (int i = 0; i < size; ++i)
	{
		p[i] = i;
	}
	for (int i = 0; i < size; ++i)
	{
		std::cout << p[i] << std::endl;
	}
	mm_free(p);
	std::cout << "free done !" << std::endl;
	mm_close();
	return 0;
}
