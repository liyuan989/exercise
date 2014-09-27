#include <iostream>
#include <string>

class NoName
{
public:
	NoName(): pstring(NULL), ival(0), dval(0.0) {}
	NoName(std::string *p, int iv, double dv): pstring(p), ival(iv), dval(dv) {}
	~NoName(){}

private:
	std::string *pstring;
	int ival;
	double dval;
};

int main(int argc, char const *argv[])
{
	
	return 0;
}