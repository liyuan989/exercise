#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string st[] = {"hello","world","boy"};
	vector<string> ivec(st, st+3);
	const char *array[ivec.size()];
	int i = 0;
	for (vector<string>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter ,++i)
	{
		array[i] = (*iter).c_str();
		cout<<array[i]<<endl;
	}
	const char *str1 = array[0];
	const char *str2 = array[1];
	const char *str3 = array[2];
	array[0] = str1;
	array[1] = str2;
	array[2] = str3;
	return 0;
}