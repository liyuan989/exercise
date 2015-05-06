/*
我们把只包含因子2、3和5的数称作丑数(Ugly Number)。求按从小
到大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，
因为它包含因子7。习惯上我们把1当作第一个丑数。
*/

#include <vector>
#include <stdio.h>

int minOfThree(int a, int b, int c)
{
    int tmp = a < b ? a : b;
    return tmp < c ? tmp : c;
}

void printNthUglyNumber(int n)
{
    if (n <= 0)
    {
        return;
    }
    std::vector<int> array;
    array.reserve(n);
    array.push_back(1);
    int min2 = 0;
    int min3 = 0;
    int min5 = 0;
    int index = 1;
    while (index < n)
    {
        array.push_back(minOfThree(array[min2] * 2, array[min3] * 3, array[min5] * 5));
        while (array[min2] * 2 <= array[index])
        {
            ++min2;
        }
        while (array[min3] * 3 <= array[index])
        {
            ++min3;
        }
        while (array[min5] * 5 <= array[index])
        {
            ++min5;
        }
        ++index;
    }
    printf("%d\n", array[n - 1]);
}

int main(int argc, char* argv[])
{
    for (int i = 0; i <= 10; ++i)
    {
        printNthUglyNumber(i);
    }
    printNthUglyNumber(1500);
    return 0;
}
