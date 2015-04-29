/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之
数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组
的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该
数组的最小值为1。
*/

#include <stdio.h>
#include <assert.h>

int minOrder(int* start, int* end)
{
    int min = *start;
    while (start <= end)
    {
        if (*start < min)
        {
            min = *start;
        }
        ++start;
    }
    return min;
}

int min(int* array, int size)
{
    assert(array);
    assert(size > 0);
    int start = 0;
    int end = size - 1;
    int middle = start;
    while (array[start] >= array[end])
    {
        if (start + 1 == end)
        {
            middle = end;
            break;
        }
        middle = (start + end + 1) / 2;
        if (array[start] == array[middle] && array[middle] == array[end])
        {
            return minOrder(&array[start], &array[end]);
        }
        if (array[middle] >= array[start])
        {
            start = middle;
        }
        else
        {
            end = middle;
        }
    }
    return array[middle];
}

int main(int argc, char* argv[])
{
    {
        int array[] = {3, 4, 5, 1, 2};
        assert(min(array, sizeof(array) / sizeof(int)) == 1);
    }
    {
        int array[] = {1, 0, 1, 1, 1};
        assert(min(array, sizeof(array) / sizeof(int)) == 0);
    }
    {
        int array[] = {1, 1, 1, 0, 1};
        assert(min(array, sizeof(array) / sizeof(int)) == 0);
    }
    {
        int array[] = {1, 2, 3, 4, 5};
        assert(min(array, sizeof(array) / sizeof(int)) == 1);
    }
    return 0;
}
