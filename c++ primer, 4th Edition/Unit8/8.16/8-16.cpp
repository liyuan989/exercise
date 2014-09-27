#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

vector<string> &SaveInVector(vector<string> &ivec, string &FileName)
{
	ifstream finput(FileName.c_str());
	if (!finput)
	{
		cout << "invalid file" << endl;
	}
	string s;
	while(!finput.eof())
	{
		getline(finput, s);
		ivec.push_back(s);
	}
	return ivec;
}

istringstream &ReadInVector(istringstream &sinput, vector<string> &ivec)
{
	vector<string>::iterator iter = ivec.begin();
	string s;
	while(iter != ivec.end())
	{
		sinput.str(*iter);
		while(!sinput.eof())
		{
			sinput >> s;
			cout << s <<endl;
		}
		sinput.clear();
		++iter;
	}
	return sinput;
}

int main(int argc, char const *argv[])
{
	istringstream sinput;
	vector<string> ivec;
	string FileName("1.txt");
	SaveInVector(ivec, FileName);
	ReadInVector(sinput, ivec);
	return 0;
}