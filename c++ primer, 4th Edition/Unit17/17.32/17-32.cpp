#include <string>
#include <vector>

struct Base1 
{
	void print(int) const;
protected:
	int ival;
	double dval;
	char cval;
private:
	int *id;
};

struct Base2 
{
	void print(double) const;
protected:
	double fval;
private:
	double dval;
};

struct Derived : public Base1 
{
	void print(std::string) const;
protected:
	std::string sval;
	double dval;
};
struct MI : public Derived, public Base2 
{
	void print(std::vector<double>);
	void foobar(double cval)
	{
		int dval;
		dval = Base1::dval;
		dval = Derived::dval;
		Base2::fval = dvec.back();
		Derived::sval = Base1::cval;
	}
protected:
	int* 				ival;
	std::vector<double> dvec;
};