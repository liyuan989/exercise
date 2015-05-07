/*
统计一个数字在排序数组中出现的次数。例如输入数组{1,2,3,3,3,3,4,5}和数字3，
由于3在这个数组中出现了4次，因此输出4。
*/

#include <assert.h>
#include <stdio.h>

int getFirstNumberIndex(int* array, int start, int end, int n)
{
    if (start > end)
    {
        return -1;
    }
    int middle = (start + end + 1) / 2;
    if (n == array[middle])
    {
        if ((middle > 0 && array[middle - 1] < n) || middle == 0)
        {
            return middle;
        }
        else
        {
            return getFirstNumberIndex(array, start, middle - 1, n);
        }
    }
    else if (n < array[middle])
    {
        return getFirstNumberIndex(array, start, middle - 1, n);
    }
    else
    {
        return getFirstNumberIndex(array, middle + 1, end, n);
    }
}

int getLastNumberIndex(int* array, int start, int end, int n, int length)
{
    if (start > end)
    {
        return -1;
    }
    int middle = (start + end + 1) / 2;
    if (n == array[middle])
    {
        if ((middle < length - 1 && array[middle + 1] > n) || middle == length - 1)
        {
            return middle;
        }
        else
        {
            return getLastNumberIndex(array, middle + 1, end, n, length);
        }
    }
    else if (n < array[middle])
    {
        return getLastNumberIndex(array, start, middle - 1, n, length);
    }
    else
    {
        return getLastNumberIndex(array, middle + 1, end, n, length);
    }
}

int countOfNumber(int* array, int size, int n)
{
    if (array == NULL || size <= 0)
    {
        return 0;
    }
    int first = getFirstNumberIndex(array, 0, size - 1, n);
    int last = getLastNumberIndex(array, 0, size - 1, n, size);
    if (first == -1 || last == -1)
    {
        return 0;
    }
    return last - first + 1;
}

int main(int argc, char* argv[])
{
    int array[] = {1,2,3,3,3,3,4,5};
    assert(countOfNumber(NULL, 8, 1) == 0);
    assert(countOfNumber(array, 0, 8) == 0);
    assert(countOfNumber(array, -1, 0) == 0);
    assert(countOfNumber(array, 8, -1) == 0);
    assert(countOfNumber(array, 8, 0) == 0);
    assert(countOfNumber(array, 8, 1) == 1);
    assert(countOfNumber(array, 8, 2) == 1);
    assert(countOfNumber(array, 8, 3) == 4);
    assert(countOfNumber(array, 8, 4) == 1);
    assert(countOfNumber(array, 8, 5) == 1);
    assert(countOfNumber(array, 8, 6) == 0);
    printf("all test case passed!\n");
    return 0;
}
