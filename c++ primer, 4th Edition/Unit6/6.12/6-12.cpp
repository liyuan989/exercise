#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	vector<string> ivec;
	cout<< "please input a list of string" << endl;
	while (cin >> str)
	{
		if (str == "#")
		{
			break;
		}
		ivec.push_back(str);
	}
	int max = 0;
	string MaxStr;
	for (vector<string>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		int n = 0;
		for (vector<string>::iterator iter2 = ivec.begin(); iter2 != ivec.end(); ++iter2)
		{
			if (*iter == *iter2)
			{
				++n;
			}
		}
		if (n > max)
		{
			max = n;
			MaxStr = *iter;
		}
	}
	cout << "the max string is "<< MaxStr << endl <<"The max numer is "<< max << endl;
	return 0;
}