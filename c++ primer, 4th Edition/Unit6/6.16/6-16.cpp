#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int array1[] = {0,1,1,2};
	int array2[] = {0,1,1,2,3,5,8};
	vector<int> ivec1(array1, array1 + 4);
	vector<int> ivec2(array2, array2 + 7);
	int n = ivec1.size() > ivec2.size() ? ivec2.size() : ivec1.size();
	for (vector<int>::iterator iter1 = ivec1.begin(), iter2 = ivec2.begin(); iter1 < ivec1.begin() + n; ++iter1, ++iter2)
	{
		if (*iter1 != *iter2)
		{
			cout<< "false" << endl;
			break;
		}
		if (*iter1 == ivec1[n-1])
		{
			cout<< "true" <<endl;
			//break;
		}
	}
	return 0;
}