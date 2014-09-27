#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char ch;
	int aCnt = 0,
		ACnt = 0,
		eCnt = 0,
		ECnt = 0,
		iCnt = 0,
		ICnt = 0,
		oCnt = 0,
		OCnt = 0,
		uCnt = 0,
		UCnt = 0,
		spCnt = 0,
		tCnt = 0,
		enCnt = 0;
	while (cin.get(ch))
	{
		if (ch == '#')
		{
			break;
		}
		switch (ch)
		{
			case 'a':
				++aCnt;
				break;
			case 'A':
				++ACnt;
				break;
			case 'e':
				++eCnt;
				break;
			case 'E':
				++ECnt;
				break;
			case 'i':
				++iCnt;
				break;
			case 'I':
				++ICnt;
				break;
			case 'o':
				++oCnt;
				break;
			case 'O':
				++OCnt;
				break;	
			case 'u':
				++uCnt;
				break;
			case 'U':
				++UCnt;
				break;
			case ' ':
				++spCnt;
				break;
			case '\t':
				++tCnt;
				break;
			case '\n':
				++enCnt;
				break;
		}
	}
	cout << "Number of vowel a: \t" << aCnt << endl
		 << "Number of vowel A: \t" << ACnt << endl
		 << "Number of vowel e: \t" << eCnt << endl
		 << "Number of vowel E: \t" << ECnt << endl
		 << "Number of vowel i: \t" << iCnt << endl
		 << "Number of vowel I: \t" << ICnt << endl
		 << "Number of vowel o: \t" << oCnt << endl
		 << "Number of vowel O: \t" << OCnt << endl
		 << "Number of vowel u: \t" << uCnt << endl
		 << "Number of vowel U: \t" << UCnt << endl
		 << "Number of vowel space \t" << spCnt <<endl
		 << "Number of vowel tab: \t" << tCnt <<endl
		 << "Number of vowel enter: \t" << enCnt <<endl;
	return 0;
}