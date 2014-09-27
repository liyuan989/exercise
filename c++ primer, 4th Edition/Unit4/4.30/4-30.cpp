#include <iostream>
#include <string>
#include <cstring>
using namespace std;

 void *Cstr_cat(char str1[], char str2[], char str[])
{
	size_t size = strlen(str1) + strlen(str2);
	if (size >= strlen(str))
	{
		strncpy(str, str1 ,strlen(str1));
		strncat(str, str2, strlen(str2));
		cout<<str<<endl;
	}
	else
		cout<<"error"<<endl;
}

void Str_cat(string str1, string str2, string str)
{
	str = str1 + str2;
	cout<<str<<endl;	
}

int main(int argc, char const *argv[])
{
	char s1[] = "hello";
	char s2[] = "world";
	char s[12];
	Cstr_cat(s1, s2, s);
	string st1 = "hello";
	string st2 = "world";
	string st;
	Str_cat(st1, st2, st);
	return 0;
}