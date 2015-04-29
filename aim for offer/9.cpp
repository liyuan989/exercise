/*
写一个函数，输入n，求斐波那契数量的第n项。

或

一只青蛙一次可以跳上一级台阶，也可以跳两级。求
该青蛙跳上n级台阶总共有多少种跳法
*/

#include <stdio.h>
#include <assert.h>

int fibonacci_recursive(int n)
{
    assert(n >= 0);
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_loop(int n)
{
    assert(n >= 0);
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int sum_n1 = 0;
    int sum_n2 = 1;
    int sum;
    for (int i = 2; i <= n; ++i)
    {
        sum = sum_n1 + sum_n2;
        sum_n1 = sum_n2;
        sum_n2 = sum;
    }
    return sum;
}

int main(int argc, char* argv[])
{
    printf("%d\n", fibonacci_recursive(10));
    printf("%d\n", fibonacci_loop(40));
    return 0;
}
