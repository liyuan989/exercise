#include <iostream>
#include <stdexcept>

typedef int EXCPTYPE;

enum mathErr
{	
	overflow,
	underflow,
	zeroDivide
};

class exceptionType 
{
};

int main(int argc, char const *argv[])
{
	try
	{
		try
		{
			try
			{
				try
				{
					exceptionType obj;
					exceptionType *p = &obj;
					throw p;
				}
				catch (const exceptionType *e)
				{
					std::cout << "exceptionType" << std::endl;
					throw mathErr();
				}
			}
			catch (const mathErr &e)
			{
				std::cout << "mathErr" << std::endl;
				throw int();
			}
		}
		catch (const EXCPTYPE &e)
		{
			std::cout << "int" << std::endl;
			throw;
		}
	}
	catch (...)
	{
		std::cout << "any error" << std::endl;
	}

	return 0;
}