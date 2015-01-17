#include <iostream>

int div16(int x)
{
	int tmp = x >> 31 & 0xF;
	return (x + tmp) >> 4;
}

int main(int argc, char const *argv[])
{
	std::cout << div16(30);
	return 0;
}