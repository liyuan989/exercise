#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<string*> ivec;
	string str;
	cout<<"please input a list of string"<<endl;
	while (cin>>str && (str != "#"))
	{
		string *pstr = new string;
		*pstr = str;
		ivec.push_back(pstr);
	}
	vector<string*>::iterator iter = ivec.begin();
	while (iter != ivec.end())
	{
		cout<<**iter<<endl;
		cout<<"the sizeof string is "<<(**iter).size()<<endl;
		++iter; 
	}
	iter = ivec.begin();
	while (iter != ivec.end())
	{
		delete *iter;
		*iter = NULL;
		++iter;
	}
	return 0;
}