#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
	string line1 = "We were her pride of 10 she named us:";
	string line2 = "Benjamin, Phoenix, the Prodigal";
	string line3 = "and perspicacious pacific Suzanne";
	string sentence = line1 + ' ' + line2 + ' ' + line3;
	int n = 0;
	for (string::size_type pos = 0; pos != sentence.size() ; ++pos)
	{
		string::size_type mid = sentence.find(" ", pos);
		if (mid != string::npos)
		{
			pos = mid;
			++n;
		}
	}

	cout << "the sentence has " << n + 1 << " words" << endl;
	istringstream input(sentence);
	vector<string> svec;
	string s;
	while(!input.eof())
	{	
		input >> s;
		svec.push_back(s);
	}
	int maxsize = 0;
	for (vector<string>::iterator it = svec.begin(); it != svec.end(); ++it)
	{
		if (it->size() > maxsize)
		{
			maxsize = it->size();
		}
	}
	cout <<"the max word: ";
	for (vector<string>::iterator it = svec.begin(); it != svec.end(); ++it)
	{
		if (it->size() == maxsize)
		{
			cout << *it << "\t";
		}
	}
	cout << endl;
	int minsize = maxsize;
	for (vector<string>::iterator it = svec.begin(); it != svec.end(); ++it)
	{
		if (it->size() < minsize)
		{
			minsize = it->size();
		}
	}
	cout <<"the min word: ";
	for (vector<string>::iterator it = svec.begin(); it != svec.end(); ++it)
	{
		if (it->size() == minsize)
		{
			cout << *it << "\t";
		}
	}
	cout << endl;
	return 0;
}