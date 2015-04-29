/*
请实现一个函数。输入一个整数，输出该二进制表示中1的个数。
例如把9表示为二进制是1001，有2位是1。因此如果输入9，则该函数输出2。
*/

#include <stdio.h>

int numBits(int n)
{
    int num = 0;
    for (size_t i = 0; i < 32; ++i)
    {
        if (n & (1 << i))
        {
            ++num;
        }
    }
    return num;
}

int numBitsEffective(int n)
{
    int num = 0;
    while (n)
    {
        ++num;
        n = n & (n - 1);
    }
    return num;
}

int main(int argc, char* argv[])
{
    printf("%d\n", numBits(0));
    printf("%d\n", numBits(255));
    printf("%d\n", numBits(-1));
    printf("%d\n", numBitsEffective(0));
    printf("%d\n", numBitsEffective(255));
    printf("%d\n", numBitsEffective(-1));
    return 0;
}
