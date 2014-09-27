#include <string>
#include <utility>

class Person
{
public:
	Person(std::string &s1, std::string &s2)
	{
		name = s1;
		address = s2;
	}
	std::pair<std::string, std::string> get_info() const
	{
		return std::make_pair(name, address);
	}
	~Person();

private:
	std::string name;
	std::string address;
};

int main(int argc, char const *argv[])
{
	
	return 0;
}