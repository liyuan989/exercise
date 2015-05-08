/*
把n个骰子仍在地上，所有骰子朝上一面的点数之和为s。
输入n，打印出s的所有可能的值出现的概率。
*/

#include <stdlib.h>
#include <stdio.h>

int pow(int base, int n)
{
    int val = 1;
    for (int i = 0; i < n; ++i)
    {
        val *= base;
    }
    return val;
}

void doPrintRateOfSum(int* array, int origin_num, int index, int sum)
{
    if (index == 1)
    {
        ++array[sum - origin_num];
        return;
    }
    else
    {
        for (int i = 1; i <= 6; ++i)
        {
            doPrintRateOfSum(array, origin_num, index - 1, sum + i);
        }
    }
}

void printRateOfSum(int num)
{
    if (num <= 0)
    {
        return;
    }
    int size = 6 * num - num + 1;
    int* array = new int[size]();
    int total = pow(6, num);
    for (int i = 1; i <= 6; ++i)
    {
        doPrintRateOfSum(array, num, num, i);
    }
    for (int i = 0; i < size; ++i)
    {
        printf("%-5d: %f\n", num + i, static_cast<double>(array[i]) / total);
    }
    delete [] array;
}

void printRateOfSumLoop(int num)
{
    if (num <= 0)
    {
        return;
    }
    int size = 6 * num + 1;
    int* array[2];
    array[0] = new int[size]();
    array[1] = new int[size]();
    for (int i = 1; i <= 6; ++i)
    {
        array[0][i] = 1;
    }
    int flag = 0;
    for (int i = 2; i <= num; ++i)
    {
        flag = 1 - flag;
        for (int j = 0; j < i; ++j)
        {
            array[flag][j] = 0;
        }
        for (int j = i; j <= 6 * i; ++j)
        {
            array[flag][j] = 0;
            for (int k = 1; k <= 6 && j > k; ++k)
            {
                array[flag][j] += array[1 - flag][j - k];
            }
        }
    }
    int total = pow(6, num);
    for (int i = num; i < size; ++i)
    {
        printf("%-5d: %f\n", i, static_cast<double>(array[flag][i]) / total);
    }
    delete [] array[0];
    delete [] array[1];
}

int main(int argc, char* argv[])
{
    printRateOfSum(6);
    printf("------------------\n");
    printRateOfSumLoop(6);
    return 0;
}
