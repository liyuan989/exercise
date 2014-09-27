#include <iostream>
#include <fstream>
#include <string>
using namespace std;

istream& process(istream& cin)
{
	int ch;
	string s;
	while (!cin.eof())
	{
		cin >> ch;
		if (cin.rdstate() == ios::failbit)
		{
			cin.clear();
			cin >> s;
			cout << s << endl;
		}
		else
			cout << ch << endl;
	}
	cin.clear();
	cin.sync();
}

ifstream &OpenInFile(ifstream &input, string &FileName)
{
	input.close();
	input.clear();
	input.open(FileName.c_str());
	return input;
}

int main(int argc, char const *argv[])
{
	ifstream input;
	string s("1.txt");
	OpenInFile(input, s);
	process(input);
	return 0;
}