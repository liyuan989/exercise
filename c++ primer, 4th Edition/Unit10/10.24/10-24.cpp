#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
using namespace std;

string Singular(string &word)
{
	ifstream input("1.txt");
	istringstream in;
	set<string> word_exclude;
	string line;
	while(!input.eof())
	{
		getline(input, line);
		in.str(line);
		string mid;
		while(in >> mid)
		{
			word_exclude.insert(mid);
		}
		in.clear();
	}
	if (word_exclude.count(word))
	{
		return word;
	}
	else
	{
		string::iterator it = word.end();
		word.erase(it - 1);
		return word;
	}
}

int main(int argc, char const *argv[])
{
	cout << "please input the plural word" << endl;
	string word;
	while(cin >> word)
	{
		cout << Singular(word) << endl;
	}
	return 0;
}
