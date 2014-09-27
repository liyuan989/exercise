#include <string>
#include <iostream>

struct NoName 
{
	NoName(): pstring(new std::string),i(0), d(0) { }
	NoName(const NoName &obj): pstring(new std::string(*obj.pstring)), i(obj.i), d(obj.d) {}
	~NoName()
	{
		delete pstring;
		pstring = NULL;
	}
private:
	std::string *pstring;
	int i;
	double d;
};

int main(int argc, char const *argv[])
{
	NoName n;
	return 0;
}