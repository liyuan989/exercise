#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include "binary_tree.h"

int main(int argc, char const *argv[])
{
	binary_tree<char> obj(binary_tree<char>::STRING, "AB#D##C##");
	binary_tree<char> obj2(binary_tree<char>::STRING, "EG#D##C##");
	binary_tree<char>::iterator it = obj.find('D');
	binary_tree<char>::iterator it2 = obj2.find('A');
	obj.insert(it, binary_tree<char>::LEFT, it2);
	obj.print(binary_tree<char>::PREORDER);
	obj.erase(it, binary_tree<char>::LEFT);
	obj.print(binary_tree<char>::PREORDER);
	binary_tree<char> obj3(obj);
	obj3.print(binary_tree<char>::PREORDER);
	obj3 = obj2;
	obj3.print(binary_tree<char>::PREORDER);
	binary_tree<char> s1(binary_tree<char>::IN_POST_OREDER, "cbaedf", "cbefda");
	s1.print(binary_tree<char>::POSTORDER);
	system("pause");
	return 0;
}