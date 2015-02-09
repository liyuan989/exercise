#include <iostream>
#include <cstdlib>
#include "BinarySortTree.h"

int main(int argc, char const *argv[])
{
	BinarySortTree<int> obj;
	obj.insert(62);
	obj.insert(58);
	obj.insert(48);
	obj.insert(51);
	obj.insert(35);
	obj.insert(29);
	obj.insert(37);
	obj.insert(36);
	obj.insert(49);
	obj.insert(56);
	obj.insert(50);
	bool is_erased = obj.erase(48);
	if (is_erased)
	{
		std::cout << "erase 48 successful!" << std::endl;
	}
	int *p = obj.find(48);
	if (!p)
	{
		std::cout << "48 has been erased in obj!" << std::endl;
	}
	BinarySortTree<int> x(obj);
	if (x.find(49))
	{
		std::cout << "x has 49" << std::endl;
	}
	x.erase(49);
	if (!x.find(49))
	{
		std::cout <<"49 has been erased in x" << std::endl;
	}

	return 0;
}