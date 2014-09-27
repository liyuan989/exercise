#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> FileInput(string FileName)
{
	ifstream input(FileName.c_str());
	vector<string> Fname;
	if (!input)
	{
		cout << "invalid file" <<endl;
		return Fname;
	}
	string s;
	vector<string>::iterator iter = Fname.begin();
	while(getline(input, s))
	{
		Fname.push_back(s);
		input.clear();
		++iter;
	}
	input.close();
	input.clear();
	return Fname;
}

int main(int argc, char const *argv[])
{
	vector<string> ivec = FileInput("1.txt");
	vector<string>::iterator iter = ivec.begin();
	while(iter != ivec.end())
	{
		cout<< *iter++ <<endl;
	}
	return 0;
}