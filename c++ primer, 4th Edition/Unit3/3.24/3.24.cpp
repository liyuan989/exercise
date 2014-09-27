#include <iostream>
#include <bitset>
using namespace std;

void case1()
{
	bitset<32> bitvec(123581321);
	cout<<"the binary digit of bitvec is:"<<bitvec<<endl;
	for (size_t iv = 0; iv != 27; ++iv)
	{
		bitvec.set(iv);
	}
	cout<<"the binary digit of bitvec is:"<<bitvec<<endl;
}

void case2()
{
	bitset<32> bitvec;
	cout<<"please input the binary digit of 123581321:    111010111011011001110001001"<<endl;
	cin>>bitvec;
	for (size_t iv = 0; iv != 27; ++iv)
	{
		bitvec.set(iv);
	}
	cout<<"the binary digit of bitvec is:"<<bitvec<<endl;
}

int main(int argc, char const *argv[])
{
	cout<<"case1"<<endl;
	case1();
	cout<<"case2"<<endl;
	case2();
	return 0;
}