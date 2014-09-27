#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char ch;
	int ffCnt = 0,
		flCnt = 0,
		fiCnt = 0;
	while (cin >> ch)
	{
		if (ch == '#')
		{
			break;
		}
		if (ch == 'f')
		{
			//cin.sync(); 
			cin >> ch;
			switch (ch)
			{
				case 'f':
					++ffCnt;
					break;
				case 'l':
					++flCnt;
					break;
				case 'i':
					++fiCnt;
					break;
			}
		}
	}
	cout << "The number of vowel ff: \t" << ffCnt <<endl
		 << "The number of vowel fl: \t" << flCnt <<endl
		 << "The number of vowel fi: \t" << fiCnt <<endl;
	return 0;
}