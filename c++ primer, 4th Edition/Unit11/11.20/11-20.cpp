#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	int array[] = {0,1,2,3,4,5};
	std::vector<int> ivec(array, array + 6);
	for(std::vector<int>::iterator it = ivec.end() - 1; it != ivec.begin() - 1; --it)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}