/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
*/

#include <stdio.h>

bool isEvent(int n)
{
    return n & 1;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 用函数指针或者函数对象可以扩展为任意两面性的情况或者条件
void sortWithEvent(int* array, int size, bool (*func)(int n))
{
    if (array == NULL || size <= 0)
    {
        return;
    }
    int* begin = array;
    int* end = array + size - 1;
    while (begin < end)
    {
        while (begin < end && func(*begin))
        {
            ++begin;
        }
        while (begin < end && !func(*end))
        {
            --end;
        }
        if (begin < end)
        {
            swap(begin, end);
        }
    }
}

int main(int argc, char* argv[])
{
    int array[] = {1, 4, 5, 2, 3, 9, 6, 8, 0, 7};
    sortWithEvent(NULL, 10, isEvent);
    sortWithEvent(array, 0, isEvent);
    sortWithEvent(array, 10, isEvent);

    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
