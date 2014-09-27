#include <iostream>
#include <string>

class Class
{
public:
	Class(){ }
};

class Base : virtual public Class
{
public:
	Base() { }

	Base(std::string s)
		: name(s) { }

	Base(const Base& s)
		: Class(s), name(s.name) { }
protected:
	std::string name;
};

class Derived1 : virtual public Base
{
public:
	Derived1()
		: Base() { }

	Derived1(std::string s)
		: Base(s) { }

	Derived1(const Derived1& s)
		: Base(s) { }
};

class Derived2 : virtual public Base
{
public:
	Derived2()
		: Base() { }

	Derived2(std::string s)
		: Base(s) { }

	Derived2(const Derived2& s)
		: Base(s) { }
};

class MI : public Derived1, public Derived2
{
public:
	MI()
		: Base() { }

	MI(std::string s)
		: Base(s), Derived1(s), Derived2(s) { }

	MI(const MI &s)
		: Base(s), Derived1(s), Derived2(s) { }
};

class Final : public MI, virtual public Class
{
public:
	Final()
		: MI(), Class() { }

	Final(std::string s)
		: MI(s), Class() { }

	Final(const Final &s)
		: MI(s), Class(s) { }
};
