#include <iostream>
#include <string>
#include <vector>

template<typename T>
size_t count(const std::vector<T> &obj, const T &val)
{
	size_t counts = 0;
	for (typename std::vector<T>::const_iterator iter = obj.begin(); iter != obj.end(); ++iter)
	{
		if (*iter == val)
		{
			++counts;
		}
	}
	return counts;
}

template<>
size_t count(const std::vector<std::string> &obj, const std::string &val);

int main(int argc, char const *argv[])
{
	std::vector<int> ivec(9, 8);
	std::vector<double> dvec(8, 9.9);
	std::vector<char> cvec(7, 'h');
	std::cout << count(ivec, 8) << std::endl;
	std::cout << count(dvec, 9.9) << std::endl;
	std::cout << count(cvec, 'h') << std::endl;

	std::vector<std::string> svec(6, "hey");
	std::cout << count(svec, std::string("hey")) << std::endl;
	return 0;
}

template<>
size_t count(const std::vector<std::string> &obj, const std::string &val)
{
	size_t counts = 0;
	for (std::vector<std::string>::const_iterator iter = obj.begin(); iter != obj.end(); ++iter)
	{
		if (*iter == val)
		{
			++counts;
		}
	}
	std::cout << "string func" << std::endl;
	return counts;
}