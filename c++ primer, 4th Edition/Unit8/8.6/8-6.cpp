#include <iostream>
#include <fstream>
using namespace std;

istream& process(istream& cin)
{
	int ch;
	while (cin >> ch && cin.eof())
	{
		cout << ch <<endl;
	}
	cin.clear();
	cin.sync();
}

int main(int argc, char const *argv[])
{
	ifstream input("1.txt");
	if (!input)
	{
		cout << "error" << endl;
	}
	process(input);
	return 0;
}