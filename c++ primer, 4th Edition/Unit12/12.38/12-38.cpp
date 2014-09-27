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

int main(int argc, char const *argv[])
{
	Foo m;
	std::cout << m.get() << std::endl;
	return 0;
}