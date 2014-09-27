#include <iostream>
#include <string>

class Date
{
public:
	Date(): year(0), month(0), day(0) {}
	Date(int y, int m, int d): year(y), month(m), day(d) {}
	~Date(){}
	friend std::ostream& operator<<(std::ofstream &output, Date &obj);

private:
	int year;
	int month;
	int day;
};

std::ostream& operator<<(std::ofstream &output, Date &obj)
{
	std::cout << obj.year << "\t" << obj.month << "\t" << obj.day;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}