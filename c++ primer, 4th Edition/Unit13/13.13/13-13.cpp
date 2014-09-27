#include <iostream>
#include <string>

class Employee
{
public:
	Employee(): pname(new std::string) {}
	Employee(const Employee& obj):name(obj.name), pname(new std::string(*obj.pname)) {}
	Employee& operator=(Employee &obj)
	{
		name = obj.name;
		*pname = *obj.pname;
	}
	~Employee()
	{
		delete pname;
		pname = NULL;
	}

private:
	std::string name;
	std::string *pname;
};

int main(int argc, char const *argv[])
{
	
	return 0;
}