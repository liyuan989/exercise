#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>
#include "textcheck.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;
using std::ifstream;
using std::istringstream;

void textcheck::load_file(std::ifstream &input)
{
	string line;
	while(getline(input, line))
	{
		word_line.push_back(line);
	}
}

void textcheck::run_file()
{
	for (textcheck::line_n n = 0; n != word_line.size(); ++n)
	{
		istringstream in(word_line[n]);
		string word;
		while(in >> word)
		{
			if (!word_map.count(word))
			{
				word_map[word].push_back(n);
			}
			else
			{
				if(word_map[word].back() < n)
					word_map[word].push_back(n);
			}
		}
	}
}

vector<textcheck::line_n> textcheck::check_out(const string &word) const
{
	map<string, vector<textcheck::line_n> >::const_iterator it = word_map.find(word);
	if (it == word_map.end())
	{
		return vector<textcheck::line_n>();
	}
	return it->second;
}

void textcheck::print_result(vector<textcheck::line_n> &val, string word, textcheck &check) const
{
	string times = val.size() > 1 ? "times" : "time";
	cout << word <<" occurs " << val.size() << " " << times << endl;
	for(textcheck::line_n n = 0; n != val.size(); ++n)
	{
		cout << "\t" << "(line " << val[n] + 1 << ") " << word_line[val[n]] << endl;
	} 
}

int main(int argc, char const *argv[])
{
	ifstream input;
	if (argc == 2)
	{
		input.open(argv[1]);
	}
	else if(argc < 2)
	{
		cout << "please input the target file" << endl;
		string file;
		cin >> file;
		input.open(file.c_str());
	}
	textcheck check;
	check.load_file(input);
	check.run_file();
	while(true)
	{
		cout << "please input the word to check, or q to quit" << endl;
		string word;
		cin >> word;
		if (word == "q")
		{
			return 0;
		}
		vector<textcheck::line_n> val = check.check_out(word);
		check.print_result(val, word, check);
		cout << endl;
	}
	return 0;
}



