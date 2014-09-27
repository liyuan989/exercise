#include <iostream>
#include <typeinfo>

class A
{
public:
	A():a(0) { }
	virtual ~A() { }
	int a;
};

class B : virtual public A
{
public:
	B():b(0) { }
	int b;
};

class C : public B
{
public:
	C():c(0) { }
	int c;
};

class D : virtual public A
{
public:
	D():d(0) { }
	int d;
};

int main(int argc, char const *argv[])
{
	try
	{
		A *pa = new C;
		C &pc = dynamic_cast<C&>(*pa);
		// use C's member
		std::cout <<"use C's member" << std::endl;
	}
	catch (std::bad_cast &e)
	{
		std::cout << e.what() << std::endl;
		std::cout <<"catched exception" << std::endl;
		// use A's member
	}
}