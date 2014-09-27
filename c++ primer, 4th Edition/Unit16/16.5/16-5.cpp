#include <iostream>
#include <string>

template <typename T>
inline const T& IsGreater(const T &obj1, const T &obj2)
{
	return obj1 > obj2 ? obj1 : obj2;
}

int main(int argc, char const *argv[])
{
	std::cout << IsGreater(1, 2) << std::endl;
	std::cout << IsGreater("helly", "heyoi") << std::endl;
	std::cout << IsGreater(2.2, 9.8) << std::endl;
	return 0;
}