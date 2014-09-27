#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int array[] = {0,1,2,3,4};
	int array2[5];
	vector<int> ivec(array,array+5);
	int number = 0;
	cout<<"the array2 is :"<<endl;
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter, ++number)
	{
		array2[number] = *iter;
		cout<<"array2["<<number<<"] = "<<array2[number]<<endl;
	}
	return 0;
}