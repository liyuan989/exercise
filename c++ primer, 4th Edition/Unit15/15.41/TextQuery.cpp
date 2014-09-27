#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>
#include <cstdlib>
#include "TextQuery.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::map;
using std::set;

void TextQuery::open_file(std::ifstream &is, std::string filename)
{
	is.close();
	is.clear();
	is.open(filename.c_str());
	if (!is)
	{
		throw std::runtime_error("invalid file");
	}
}

void TextQuery::store_file(std::ifstream &is)
{
	string txt_line;
	while(getline(is, txt_line))
	{
		line_of_text.push_back(txt_line);
	}
}

void TextQuery::build_map()
{
	for (line_no line_num = 0; line_num != line_of_text.size(); ++line_num)
	{
		istringstream in(line_of_text[line_num]);
		string word;
		while(in >> word)
		{
			word_map[word].insert(line_num);
		}
	}
}

void TextQuery::read_file(std::ifstream &is)
{
	store_file(is);
	build_map();
}

set<TextQuery::line_no> TextQuery::run_query(const string &check_word) const
{
	map<string, set<line_no> >::const_iterator it = word_map.find(check_word);
	if (it == word_map.end())
	{
		return set<line_no>();
	}
	return it->second;
}

string TextQuery::text_line(TextQuery::line_no line) const
{
	if (line < line_of_text.size())
	{
		return line_of_text[line];
	}
	else
		throw std::out_of_range("line number out of range");
}

void TextQuery::print_result(set<TextQuery::line_no>& target_set, TextQuery& check)
{
	string time_tail = target_set.size() > 1 ? "times" : "time";
	cout << endl << "match occuers " << target_set.size() << " " << time_tail << endl << endl;
	set<TextQuery::line_no>::iterator it = target_set.begin();
	for(int n = 0; n != target_set.size(); ++n, ++it)
	{
		cout << "\t" << "(line " << *it + 1 << ") " << check.text_line(*it) << endl;
	}
}
/*
int main(int argc, char const *argv[])
{
	string file;
	if(argc <= 1)
	{
		cout << "please input the target file" << endl;
		cin >> file;
	}
	else if(argc == 2)
	{
		file = argv[1];
	}
	else
	{
		return EXIT_FAILURE;
	}
	ifstream input(file.c_str());
	TextQuery check;
	check.read_file(input);
	while(1)
	{
		cout << "enter word to check,or q to quit" << endl;
		string word;
		cin >> word;
		if (word == "q")
		{
			break;
		}
		set<TextQuery::line_no> target_set = check.run_query(word);
		check.print_result(target_set, word, check);
	}
	return 0;
}
*/