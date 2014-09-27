#include <iostream>
#include <string>
#include "vector.h"

int main(int argc, char const *argv[])
{
	ly::vector<int> ivec;
	//ivec.get();
	for (int i = 0; i < 8; ++i)
	{
		ivec.push_back(i);
	}
	//std::cout << ivec.size() <<"\n";
	for (int i = 0; i < ivec.size(); ++i)
	{
		std::cout << ivec[i] << " ";
	}
	std::cout << "\n";
	ivec.resize(10,2);
	for (int i = 0; i < ivec.size(); ++i)
	{	
		std::cout << ivec[i] << " ";
	}
	std::cout << "\n";
	std::cout << ivec.size() << "\n";
	std::cout << ivec.capacity() << "\n";
	int a[] = {4,3,2,1};
	ivec.assign(a, a + 4);
	std::cout << ivec.capacity() << "\n";
	ivec.reserve(3);
	std::cout << ivec.capacity() << "\n";
	for (int i = 0; i < ivec.size(); ++i)
	{	
		std::cout << ivec.at(i) << " ";
	}
	std::cout<<"\n";
	ivec.insert(ivec.begin(), 2);
	std::cout << ivec.capacity() << "\n";
	for (int i = 0; i < ivec.size(); ++i)
	{	

		std::cout << ivec.at(i) << " ";
	}
	int a1[] = {0,1,2,3,4,5};
	int b1[] = {0,1,2,3,4,5};
	ly::vector<int> test1(a1,a1+6);
	ly::vector<int> pl(b1,b1+4);
	pl.reserve(10);
	ly::vector<int>::reverse_iterator it = test1.rbegin();

}
