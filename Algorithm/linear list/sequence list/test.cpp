#include <iostream>
#include <string>
#include "SequenceList.h"

int main(int argc, char const *argv[])
{
	SequenceList<int> iseq;
	int *p = iseq.begin();
	iseq.insert(p, 1);
	std::cout << iseq[0] << "\n";
	p = iseq.begin();
	iseq.insert(p + 1, 2);
	std::cout << iseq[1] << "\n";
	iseq.erase(iseq.begin());
	std::cout << iseq[0];
}