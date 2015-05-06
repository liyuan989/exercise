/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。例如输入数组{3,32,321}，
则打印出321323。
*/

#include <algorithm>
#include <string.h>
#include <stdio.h>

bool compare(int a, int b)
{
    char s1[100];
    char s2[100];
    snprintf(s1, sizeof(s1), "%d%d", a, b);
    snprintf(s2, sizeof(s2), "%d%d", b, a);
    if (strcmp(s1, s2) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printMin(int* array, int size)
{
    if (array == NULL || size <= 0)
    {
        return;
    }
    std::sort(array, array + size, compare);
    char s[100];
    int n = 0;
    for (int i = 0; i < size; ++i)
    {
        n += snprintf(s + n, sizeof(s) - n, "%d", array[i]);
    }
    printf("%s\n", s);
}

int main(int argc, char* argv[])
{
    int array[] = {3, 32, 321};
    printMin(array, 3);
    return 0;
}
