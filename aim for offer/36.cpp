/*
在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组的逆序对的总数。
*/

#include <stdio.h>

int doSumOfReversePair(int* array, int* copy, int start, int end)
{
    if (start == end)
    {
        return 0;
    }
    int middle = (start + end + 1) / 2;
    int left_count = doSumOfReversePair(copy, array, start, middle - 1);
    int right_count = doSumOfReversePair(copy, array, middle, end);
    int current_count = 0;
    int i = middle - 1;
    int j = end;
    int copy_index = end;
    while (i >= start && j >= middle)
    {
        if (array[i] > array[j])
        {
            current_count += j - middle + 1;
            copy[copy_index] = array[i];
            --i;
        }
        else
        {
            copy[copy_index] = array[j];
            --j;
        }
        --copy_index;
    }
    while (i >= start)
    {
        copy[copy_index] = array[i];
        --copy_index;
        --i;
    }
    while (j >= middle)
    {
        copy[copy_index] = array[j];
        --copy_index;
        --j;
    }
    return current_count + left_count + right_count;
}

int sumOfReversePair(int* array, int size)
{
    if (array == NULL || size <= 0)
    {
        return 0;
    }
    int* copy = new int[size];
    for (int i = 0; i < size; ++i)
    {
        copy[i] = array[i];
    }
    return doSumOfReversePair(array, copy, 0, size - 1);
}

int main(int argc, char* argv[])
{
    int array[] = {7, 5, 6, 4};
    printf("%d\n", sumOfReversePair(array, 4));
    return 0;
}
