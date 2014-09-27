#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

ifstream &open_file(ifstream &input , string FileName)
{
	input.close();
	input.clear();
	input.open(FileName.c_str());
	if (!input)
	{
		throw runtime_error("invalid file");
	}
}

int main(int argc, char const *argv[])
{
	ifstream input;
	istringstream in;
	open_file(input, argv[1]);
	map<string, string> word_trans;
	string map_key;
	string map_val;
	while(!input.eof())
	{
		input >> map_key >> map_val;
		word_trans.insert(make_pair(map_key, map_val));
	}
	open_file(input, argv[2]);
	string str_mid;
	string word_mid;
	map<string, string>::iterator it;
	while(!input.eof())
	{
		getline(input, str_mid);
		in.str(str_mid);
		while(!in.eof())
		{
			in >> word_mid;
			it = word_trans.find(word_mid);
			if (it != word_trans.end())
			{
				cout << it->second << " ";
			}
		}
		cout << endl;
		in.clear();
	}
	system("pause");
	return 0;
}