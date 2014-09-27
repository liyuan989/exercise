#include <iostream>

class Foo
{
public:
	explicit Foo(int data_t = 0): data(data_t) {}
	int get()
	{
		return data;
	}

private:
	int data;
};

class Bar
{
public:
	
private:
	static int ia;
	static Foo f;
};

int Bar::ia = 0;
Foo Bar::f;

int main(int argc, char const *argv[])
{
	
}