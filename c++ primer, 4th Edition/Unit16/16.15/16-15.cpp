#include <iostream>

template <typename T, size_t N> 
void PrintArray(T (&ary)[N])
{
	size_t n = 0;
	while (n != N)
	{
		std::cout << ary[n] << std::endl;
		++n;
	}
}

int main(int argc, char const *argv[])
{
	int a[3] = {0,1,2};
	PrintArray(a);

	std::string b[3] = {"hey","girl","come on"};
	PrintArray(b);
	return 0;
}