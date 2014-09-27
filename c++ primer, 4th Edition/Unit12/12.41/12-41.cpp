#include <iostream>

class Foo
{
public:
	explicit Foo(int data_t = 0): data(data_t) {}
	int get() const {return data;}

private:
	int data;
};

class Bar
{
public:
	Foo &Fooval()
	{
		callsFooval();
		return f;
	}
private:
	static int ia;
	static Foo f;

	static size_t callsFooval()
	{	
		size_t count = 0;
		++count;
		return count;
	}
};

int Bar::ia = 20;
Foo Bar::f;

int main(int argc, char const *argv[])
{
	
}