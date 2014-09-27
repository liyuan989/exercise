#include <iostream>
#include <vector>

template <typename T>
void PrintContainer (const T &obj)
{
	for (typename T::size_type n = 0; n != obj.size(); ++n)
	{
		std::cout << obj[n] << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> ivec(9,7);
	PrintContainer(ivec);
	return 0;
}