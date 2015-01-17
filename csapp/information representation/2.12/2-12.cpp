#include <iostream>

int main(int argc, char const *argv[])
{
	unsigned int x = 0x87654321;
	unsigned int A = x & 0xFF;
	std::cout << std::hex << std::showbase << A << std::endl;
	unsigned int B = x ^ ~0xFF;
	std::cout << std::hex << std::showbase << B << std::endl;
	unsigned int C = x | 0xFF;
	std::cout << std::hex << std::showbase << C << std::endl;
	return 0;
}