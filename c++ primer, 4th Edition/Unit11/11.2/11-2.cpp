#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string array[] = {"0","1","1","1","2","3","4","5","7","1"};
	list<string> ivec(array, array + 10);
	int number = count(ivec.begin(), ivec.end(), "1");
	cout << number << endl;
	return 0;
}