/*
题目一：

输入一个递增排序的数组和一个数字s，在数组中查找两个数，
使得它们的和正好是s。如果有多对数字的和等于s，
输出任意一对即可。
*/

#include <stdio.h>

bool getPairbySum(int* array, int size, int n, int* num1, int* num2)
{
    if (array == NULL || size <= 0 || num1 == NULL || num2 == NULL)
    {
        return false;
    }
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        if (array[start] + array[end] == n)
        {
            *num1 = array[start];
            *num2 = array[end];
            return true;
        }
        else if (array[start] + array[end] < n)
        {
            ++start;
        }
        else
        {
            --end;
        }
    }
    return false;
}

/*
问题二：

输入一个正数s，打印所有和为s的连续正数序列(至少含有两个数)。
例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以打印3个连续序列
1~5,4~6,7~8。
*/

void print(int a, int b)
{
    for (int i = a; i <= b; ++i)
    {
        printf("%d", i);
    }
    printf("\n");
}

int sumOfSequence(int a, int b)
{
    int size = b - a + 1;
    return size * (a + b) / 2;
}

void printSequence(int sum)
{
    if (sum <= 1)
    {
        return;
    }
    int start = 1;
    int end = 2;
    while (start < end && start < (sum + 1) / 2)
    {
        int cur_sum = sumOfSequence(start, end);
        if (cur_sum == sum)
        {
            print(start, end);
            ++end;
        }
        else if (cur_sum < sum)
        {
            ++end;
        }
        else
        {
            ++start;
        }
    }
}

int main(int argc, char* argv[])
{
    int array[] = {1,2,4,7,11,15};
    int num1 = 0;
    int num2 = 0;
    getPairbySum(array, 6, 15, &num1, &num2);
    printf("%d %d\n", num1, num2);

    printSequence(15);
    return 0;
}
