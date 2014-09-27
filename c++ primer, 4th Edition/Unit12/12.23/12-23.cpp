#include <iostream>
#include <string>

class NoDefault
{
public:
	NoDefault(int at): a(at) {}
	~NoDefault(){}

private:
	int a;
};

class C
{
public:
	C(): m(0) {}
	~C(){}

private:
	NoDefault m;
};

int main(int argc, char const *argv[])
{
	
	return 0;
}