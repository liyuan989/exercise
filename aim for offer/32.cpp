/*
输一个正数n，求从1到n这n个整数的十进制表示中1出现的次数。
例如输入12，从1到12这些整数中包含1的数字有1、10、11和12，
1一共出现了5次。
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int numberOfOneInOne(int k)
{
    int count = 0;
    while (k)
    {
        if (k % 10 == 1)
        {
            ++count;
        }
        k = k / 10;
    }
    return count;
}

int getNumberOfOne(int n)
{
    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        count += numberOfOneInOne(i);
    }
    return count;
}

int power10(int n)
{
    int ret = 1;
    for (int i = 0; i < n; ++i)
    {
        ret *= 10;
    }
    return ret;
}

int getNumberOfOneStr(char* str)
{
    if (str == NULL || *str == '\0' || *str < '0' || *str > '9')
    {
        return 0;
    }
    int first = static_cast<int>(*str - '0');
    int length = strlen(str);
    if (length == 1)
    {
        return 1;
    }
    int sum_first_digit = 0;
    if (first > 1)
    {
        sum_first_digit = power10(length - 1);
    }
    else
    {
        sum_first_digit = atoi(str + 1) + 1;
    }
    int sum_other_digit = first * (length - 1) * power10(length - 2);
    return sum_first_digit + sum_other_digit + getNumberOfOneStr(str + 1);
}


// http://zhedahht.blog.163.com/blog/static/25411174200732494452636/
int getNumberOfOneEfficient(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    char str[100];
    snprintf(str, sizeof(str), "%d", n);
    return getNumberOfOneStr(str);
}

int main(int argc, char* argv[])
{
    printf("%d\n", getNumberOfOne(12));
    printf("%d\n", getNumberOfOne(21345));

    printf("%d\n", getNumberOfOneEfficient(12));
    printf("%d\n", getNumberOfOneEfficient(21345));
    return 0;
}
