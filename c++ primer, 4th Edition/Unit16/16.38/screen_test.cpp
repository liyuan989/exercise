#include "Screen.h"

int main(int argc, char const *argv[])
{
	Screen<9, 9> obj;
	std::cout << obj;
	std::cin >> obj;
	std::cout << obj;
	return 0;
}