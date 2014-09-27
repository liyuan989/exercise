#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ofstream &OpenOutFile(ofstream &output, string &FileName)
{
	output.close();
	output.clear();
	output.open(FileName.c_str());
	return output;
}

int main(int argc, char const *argv[])
{
	ofstream output;
	string s("1.txt");
	OpenOutFile(output, s);
	string a("hello");
	string b("world");
	output << a << endl;
	output << b << endl;	
	return 0;
}