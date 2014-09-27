#include <iostream>

class ZomAnimal
{
public:
	virtual void print() { std::cout << "ZomAnimal";}
	virtual void destructor() { }
	virtual ~ZomAnimal() { }
};

class Bear : public ZomAnimal
{
public:
	virtual void print() { std::cout<<"Bear";}
	virtual void toes() { }
};

class Endangered
{
public:
	virtual void print() { std::cout<<"Endangered";}
	virtual void highlight() { }
	virtual void destructor() { }
	virtual ~Endangered() { }
};

class Panda : public Bear, public Endangered
{
public:
	virtual void print() {std::cout<<"panda"; }
	virtual void destructor() { }
	virtual void toes() { }
	virtual void highlight() { }
	virtual void cuddle() { }
};

int main(int argc, char const *argv[])
{
	Panda a;
	a.print();
	return 0;
}