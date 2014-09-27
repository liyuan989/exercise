#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	vector<string> ivec;
	int n = 0;
	cout<< "please input a list of string" << endl;
	while (cin >> str)
	{
		if (str == "#")
		{
			break;
		}
		#ifndef NDEBUG
		cout << str <<endl;
		#endif
		ivec.push_back(str);
		if (n != 0 && (ivec[n] == ivec[n-1]))
		{
			string strg = ivec[n];
			if (isupper(strg[0]))
			{
				cout << "the word is " << ivec[n] << endl;
				break;
			}
		}
		++n;
	}
	return 0;
}