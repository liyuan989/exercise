/*
输入一个整型数组，数字里有正数也有负数。数组中一个或
连续的多个数组组成一个子数组。求所有子数组的最大值。
要求时间复杂度为O(N)。
*/

#include <stdexcept>
#include <stdio.h>

int maxSumOfSubArrays(int* array, int size)
{
    if (array == NULL || size <= 0)
    {
        throw std::logic_error("Invalid input");
    }
    int max_sum = 1 << 31;
    int cur_sum = 0;
    for (int i = 0; i < size; ++i)
    {
        if (cur_sum <= 0)
        {
            cur_sum = array[i];
        }
        else
        {
            cur_sum += array[i];
        }
        if (cur_sum > max_sum)
        {
            max_sum = cur_sum;
        }
    }
    return max_sum;
}

int main(int argc, char* argv[])
{
    int array[] = {1, -2, 3, 10, -4, 7, 2, -5};
    printf("%d\n", maxSumOfSubArrays(array, 8));
    return 0;
}
