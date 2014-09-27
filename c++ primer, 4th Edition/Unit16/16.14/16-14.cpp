#include <iostream>
#include <vector>

template <typename T>
void PrintContainer (T &obj)
{
	for (typename T::iterator it = obj.begin(); it != obj.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> ivec(9,7);
	PrintContainer(ivec);
	return 0;
}