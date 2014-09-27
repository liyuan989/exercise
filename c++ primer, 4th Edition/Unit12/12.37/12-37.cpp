#include <iostream>
#include <string>

class Account
{
public:
	Account(std::string name, double sum): owner(name), amount(sum) {}
	Account(): amount(0) {}
	void applyint()
	{
		amount += amount * interestRate;
	}
	static double Rate()
	{
		return interestRate;
	}
	static void Rate(double);

private:
	std::string owner;
	double amount;
	static double interestRate;

	static double initRate();
};

double Account::interestRate = 0;

void Account::Rate(double rate)
{
	interestRate = rate;
}

double Account::initRate()
{

}

int main(int argc, char const *argv[])
{
	
	return 0;
}