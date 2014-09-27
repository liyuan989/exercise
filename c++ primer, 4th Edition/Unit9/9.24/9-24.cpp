#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int array[] = {0,1,2,3,4};
	vector<int> ivec(array, array + 5);
	vector<int>::iterator iter = ivec.begin();
	cout << ivec[0] << endl;
	cout << ivec.front() <<endl;
	cout << *iter << endl;
	cout << ivec.at(0) << endl;
	return 0;
}