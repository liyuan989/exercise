#include <iostream>

int tmult_ok(int x, int y)
{
	long long z = (long long)x * y;
	return z == (long)z;
}

int main(int argc, char const *argv[])
{
	std::cout << tmult_ok(999, 999);
	return 0;
}