#include <iostream>
#include <string>
#include "DoubleList.h"

int main(int argc, char const *argv[])
{
	DoubleList<int> idou(1,8);
	std::cout << idou[1] << std::endl;
	idou.insert(idou.begin(), 10);
	std::cout << idou[1] << std::endl;
	idou.erase(idou.begin());
	std::cout << idou[1] << std::endl;
	return 0;
}