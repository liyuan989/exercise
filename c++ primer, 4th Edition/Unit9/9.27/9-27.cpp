#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

bool FindStrInList(list<string> &slist, string str)
{
	list<string>::iterator it = find(slist.begin(), slist.end(), str);
	if (it == slist.end())
	{
		return false;
	}
	else
	{
		slist.erase(it);
		return true;
	}
}

bool FindStrInDeque(deque<string> &sdeq, string str)
{
	deque<string>::iterator it = find(sdeq.begin(), sdeq.end(), str);
	if (it == sdeq.end())
	{
		return false;
	}
	else
	{
		sdeq.erase(it);
		return true;
	}
}

void InitializeList(list<string> &slist)
{
	ifstream input("1.txt");
	if (!input)
	{
		cout << "file invalid" << endl;
	}
	string s;
	while(input >> s, !input.eof())
	{
		slist.push_back(s);
	}
}

void InitializeDeque(deque<string> &sdeq)
{
	ifstream input("1.txt");
	istringstream in;
	if (!input)
	{
		cout << "file invalid" << endl;
	}
	string s;
	string st;
	while(!input.eof())
	{
		getline(input, s);
		in.str(s);
		while(!in.eof())
		{
			in >> st;
			sdeq.push_back(st);
		}
		in.clear();
	}
}

int main(int argc, char const *argv[])
{
	list<string> slist;
	deque<string> sdeq;
	InitializeList(slist);
	InitializeDeque(sdeq);
	if (FindStrInList(slist, "life"))
	{
		cout << "have delete it" << endl;
	}
	else
		cout << "don't have it" << endl;
	if (FindStrInDeque(sdeq, "life"))
	{
		cout << "have delete it" << endl;
	}
	else
		cout << "don't have it" << endl;
	return 0;
}