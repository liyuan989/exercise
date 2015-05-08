/*
写一个函数，求两个整数之和，要求在函数体内不得用
加减乘除运算。
*/

#include <assert.h>
#include <stdio.h>

int sumByBit(int a, int b)
{
    int current_xor = a ^ b;
    int current_and = (a & b) << 1;
    while (current_and != 0)
    {
        a = current_xor;
        b = current_and;
        current_xor = a ^ b;
        current_and = (a & b) << 1;
    }
    return current_xor;
}

int main(int argc, char* argv[])
{
    assert(sumByBit(0, 0) == 0);
    assert(sumByBit(1, 0) == 1);
    assert(sumByBit(-1, 0) == -1);
    assert(sumByBit(-1, 1) == 0);
    assert(sumByBit(5, 10) == 15);
    assert(sumByBit(5050, 1111) == 6161);
    assert(sumByBit(-4999, 5000) == 1);
    assert(sumByBit(-255, -255) == -510);
    printf("all test case passed!\n");
    return 0;
}
