#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include "threaded_binary_tree.h"

int main(int argc, char const *argv[])
{
	threaded_binary_tree<char> obj(threaded_binary_tree<char>::STRING, "AB#D##C##");
	obj.threaded_thravse();
	system("pause");
	return 0;
}