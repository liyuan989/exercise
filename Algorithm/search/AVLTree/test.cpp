#include <iostream>
#include <cstdlib>
#include "AVLTree.h"

int main(int argc, char const *argv[])
{
	AVLTree<int> obj;
	obj.insert(1);
	obj.insert(2);
	obj.insert(3);
	obj.insert(4);
	obj.insert(6);
	obj.insert(5);
	obj.insert(8);
	obj.insert(-1);
	obj.print();
	obj.erase(4);
	obj.print();
	return 0;
}