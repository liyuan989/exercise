#include <iostream>
#include <string>
using namespace std;
string make_plural(size_t ctr, const string &word, const string &ending = "s");
int main(int argc, char const *argv[])
{
	cout << make_plural(0, "boy") << endl;
	return 0;
}

string make_plural(size_t ctr, const string &word,const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}