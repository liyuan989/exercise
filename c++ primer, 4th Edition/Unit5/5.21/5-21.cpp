#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> ivec(array, array+10);
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		if (*iter & 1)
		{
			*iter *= 2;
		}
	}
	vector<int>::iterator iter = ivec.begin();
	int i = 0;
	while (iter != ivec.end())
	{
		cout<<"ivec["<<i++<<"] = "<<*iter++<<endl;
	}
	return 0;
}