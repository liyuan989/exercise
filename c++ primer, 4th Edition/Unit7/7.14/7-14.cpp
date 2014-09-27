#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double AddDouble(vector<double>::const_iterator beg, vector<double>::const_iterator end)
{
	double add = 0;
	for (; beg != end; ++beg)
	{
		add += *beg;
	}
	return add;
}

int main(int argc, char const *argv[])
{
	double array[] = {1.1, 1.2, 1.3, 1.4, 1.5};
	vector<double> ivec(array, array + 5);
	double add = AddDouble(ivec.begin(), ivec.end());
	cout << setprecision(4) << add << endl;
	return 0;
}