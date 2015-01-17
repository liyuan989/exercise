#include <iostream>

int tadd_ok(int x, int y)
{
	int z = x + y;
    int overflow = x && y && !z;
    int underflow = !x && !y && z;
    return !overflow && !underflow;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}