#include <string>
#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
	string str("hello");
	string::iterator iter = str.begin();
	while(iter != str.end())
	{
		*iter = toupper(*iter);
		++iter;
	}
	cout << str << endl;
}