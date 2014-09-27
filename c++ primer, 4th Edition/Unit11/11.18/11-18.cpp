#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <fstream>

bool IsOdd(int &num)
{
	return num & 0;
}

int main(int argc, char const *argv[])
{
	std::istream_iterator<int> iter_in(std::cin);
	std::istream_iterator<int> iter_eof;
	std::vector<int> ivec(iter_in, iter_eof);
	std::ofstream output1("1.txt");
	std::ofstream output2("2.txt");
	if (!(output1 || output2))
	{
		return 0;
	}
	std::ostream_iterator<int> iter_out1(output1, " ");
	std::ostream_iterator<int> iter_out2(output2, "\n");
	for (int i = 0; i < ivec.size(); ++i)
	{
		if (ivec[i] & 1)
		{
			*iter_out1++ = ivec[i];
		}
		else
		{
			*iter_out2++ = ivec[i];
		}
	}

}