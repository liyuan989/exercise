#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> ivec;
	int number;
	cout<<"please input a list of number without zero,and end of zero"<<endl;
	for (vector<int>::iterator iter = ivec.begin(); ; ++iter)
	{
		cin>>number;
		if (number == 0)
		{
			break;
		}
		ivec.push_back(number);
	}
	//cout<<ivec[ivec.size()-1]<<end;
	int array[ivec.size()];
	int iv = 0;
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter, ++iv)
	{
		array[iv] = *iter;
		cout<<"array["<<iv<<"] = "<<array[iv]<<endl;
	}
	return 0;
}