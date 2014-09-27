#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void StringComparre(string str1, string str2)
{
	if (str1 > str2)
	{
		cout<<str1<<" > "<<str2<<endl;
	}
	if (str1 < str2)
	{
		cout<<str1<<" < "<<str2<<endl;
	}
	if (str1 == str2)
	{
		cout<<str1<<" = "<<str2<<endl;
	}
}

void CstringCompare(const char *str1, const char *str2)
{
	int n = strcmp(str1, str2);
	if (n > 0)
	{
		cout<<str1<<" > "<<str2<<endl;
	}
	if (n == 0)
	{
		cout<<str1<<" = "<<str2<<endl;
	}
	if (n < 0)
	{
		cout<<str1<<" < "<<str2<<endl;
	}
}

int main(int argc, char const *argv[])
{
	string s1 = "hello";
	string s2 = "hello";
	string s3 = "hey";
	StringComparre(s1, s2);
	StringComparre(s1, s3);
	const char *str1 = "hello";
	const char *str2 = "hello";
	const char *str3 = "hey";
	CstringCompare(str1, str2);
	CstringCompare(str1, str3);
	return 0;
}