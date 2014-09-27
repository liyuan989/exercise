#include <iostream>
#include <string>

template <typename T>
inline T AbsoluteValue(const T &obj)
{
	return (obj >= 0) ? obj : (-1*obj); 
}

int main(int argc, char const *argv[])
{
	std::cout << AbsoluteValue(1) << std::endl;
	std::cout << AbsoluteValue(-1) << std::endl;
	std::cout << AbsoluteValue(9.99) << std::endl;
	std::cout << AbsoluteValue(-9.99) << std::endl;
	return 0;
}