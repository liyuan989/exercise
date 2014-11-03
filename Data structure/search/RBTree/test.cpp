#include <iostream>
#include <cstdlib>
#include "RBtree.h"

int main(int argc, char const *argv[])
{
	RBTree<int> object;
	object.insert(16);
	object.insert(8);
	object.insert(24);
	object.insert(4);
	object.insert(12);
	object.insert(20);
	object.insert(28);
	object.insert(2);
	object.print();
	object.erase(2);
	object.erase(4);
	object.erase(8);
	object.erase(24);
	object.erase(16);
	object.erase(20);
	object.erase(12);
	object.print();
	return 0;
}