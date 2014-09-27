#include <iostream>
#include <string>

class Employee
{
public:
	Employee(): pname(new std::string("hey")) 
	{
		std::cout << "Employee()" << std::endl;
	}
	Employee(const Employee& obj):name(obj.name), pname(new std::string(*obj.pname)) 
	{
		std::cout << "Employee(Employee& obj)  copy" << std::endl;
	}
	Employee& operator=(const Employee &obj)
	{
		std::cout << "Employee& operator=(Employee &obj)  =" << std::endl;
		name = obj.name;
		*pname = *obj.pname;
	}
	~Employee()
	{
		std::cout << "~Employee()" << std::endl;
		delete pname;
		pname = NULL;
	}

private:
	std::string name;
	std::string *pname;
};

Employee get(Employee s)
{
return s;
}

int main(int argc, char const *argv[])
{
	Employee s1;
	Employee s2 = get(s1);
}