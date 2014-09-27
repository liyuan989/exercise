#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string s("C++ Primer 3rd Ed");
	string s2("h4thppp");
	s.replace(11,3,s2,1,3);
	cout<<s2.find("p",3);
	
	
}
