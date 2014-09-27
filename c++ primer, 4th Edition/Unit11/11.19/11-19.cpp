#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	int array[] = {0,1,2,3,4,5};
	std::vector<int> ivec(array, array + 6);
	for(std::vector<int>::reverse_iterator it_r = ivec.rbegin(); it_r != ivec.rend(); ++it_r)
	{
		std::cout << *it_r << std::endl;
	}
	return 0;
}