#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

int main(int argc, char const *argv[])
{
	std::ifstream input("1.txt");
	if (!input)
	{
		std::cout << "invalid file" << std::endl;
	}
	//std::istream_iterator<std::string> iter_in(input);
	//std::istream_iterator<std::string> iter_eof;
	//std::vector<std::string> svec(iter_in, iter_eof);
	std::vector<std::string> svec;
	std::string s;
	while(std::getline(input, s))
	{
		svec.push_back(s);
	}
	std::ostream_iterator<std::string> iter_out(std::cout);
	/*for (std::vector<std::string>::iterator it = svec.begin(); it != svec.end(); ++it, ++iter_out)
	{
		*iter_out = *it;
	}*/
	std::copy(svec.begin(), svec.end(), iter_out);
	return 0;
}