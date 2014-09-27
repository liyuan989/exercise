#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	vector<string> svec;
	while(cin >> s, s != "#")
	{
		svec.push_back(s);
	}
	vector<string>::iterator iter = svec.begin();
	while(iter != svec.end())
	{
		cout << *iter++ << endl;
	}
	return 0;
}