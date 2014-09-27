#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	ifstream input;
	vector<string> ivec;
	ivec.push_back("1.txt");
	ivec.push_back("2.txt");
	ivec.push_back("3.txt");
	vector<string>::iterator iter = ivec.begin();
	while (iter != ivec.end())
	{
		input.open(iter++ -> c_str());
		if (!input)
		{
			cout << "error:file invalid" <<endl;
			input.close();
			input.clear();
		}
		else
		{
			input.close();
			input.clear();
		}
	}
	return 0;
}