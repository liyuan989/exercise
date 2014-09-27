#include <iostream>
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

int main(int argc, char const *argv[])
{
	process(cin);
	return 0;
}