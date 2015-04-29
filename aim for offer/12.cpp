/*
输入数字n，按顺序打印出从1到最大n位十进制数。
比如输入3，打印1、2、3一直到最大值999.
*/

//陷阱：注意不要直接用整形变量求解，整形类型上限有限，很容易越界

#include <stdio.h>
#include <string.h>

void printNumber(char* number)
{
    for (char* p = number; *p != '\0'; ++p)
    {
        if (*p != '0')
        {
            printf("%s\n", p);
            break;
        }
    }
}

bool increment(char* number)
{
    int length = strlen(number);
    for (int i = length - 1; i >= 0; --i)
    {
        if (number[i] == '9')
        {
            if (i == 0)
            {
                return false;
            }
            number[i] = '0';
        }
        else
        {
            ++number[i];
            break;
        }
    }
    return true;
}

void printOneToNDigit(int n)
{
    if (n <= 0)
    {
        return;
    }
    char* number = new char[n + 1];
    for (int i = 0; i < n; ++i)
    {
        number[i] = '0';
    }
    number[n] = '\0';
    while (increment(number))
    {
        printNumber(number);
    }
    delete [] number;
}

void doPermutation(char* number, int index)
{
    if (number[index] == '\0')
    {
        printNumber(number);
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        number[index] = static_cast<char>('0' + i);
        doPermutation(number, index + 1);
    }
}

void printOneToNDigitPermutation(int n)
{
    if (n <= 0)
    {
        return;
    }
    char* number = new char[n + 1];
    for (int i = 0; i < n; ++i)
    {
        number[i] = '0';
    }
    number[n] = '\0';
    doPermutation(number, 0);
}

int main(int argc, char* argv[])
{
    printOneToNDigit(0);
    printOneToNDigit(2);
    printOneToNDigit(-2);

    printOneToNDigitPermutation(0);
    printOneToNDigitPermutation(3);
    printOneToNDigitPermutation(-2);
    return 0;
}
