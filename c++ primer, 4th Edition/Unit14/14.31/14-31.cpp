#include <iostream>
#include <string>

class Test
{
public:
	int operator()(int a, int b, int c)
	{
		return a > 0 ? b : c;
	}
	/* data */
};

int main(int argc, char const *argv[])
{
	Test test;
	std::cout << test(1,2,3) << std::endl;

	return 0;
}