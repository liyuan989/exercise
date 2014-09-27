#include <iostream>
#include <string>
using namespace std;

inline bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main(int argc, char const *argv[])
{
	string s1("hello");
	string s2("hey");
	isShorter(s1, s2);
	return 0;
}