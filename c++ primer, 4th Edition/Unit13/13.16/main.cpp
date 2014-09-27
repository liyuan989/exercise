#include <iostream>
#include <string>
#include <set>
#include "Folder.h"
#include "Message.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	Message m("hello");
	Folder folders;
	m.save();
	system("pause");
	return 0;
}