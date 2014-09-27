#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	cout<<"s = "<<s<<endl;

	cout<<"please input a string,end with #"<<endl;
	char str[10];
	for (int i = 0; i != 10; ++i)
	{
		cin>>str[i];
		if (str[i] == '#')
		{
			str[i] = 0;
			break;
		}
	}
	char *p = str;
	while (*p)
	{
		cout<<*p;
		++p;
	}
	return 0;
}