/*
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌
是不是连续的。2~10为数字本身，A为1，J为11，Q为12，K为13，
而大小王可以看成任意数字。
*/

// 假设大小王都为0

#include <algorithm>
#include <assert.h>
#include <stdio.h>

bool isSequence(int* array, int size)
{
    if (array == NULL || size <= 1)
    {
        return false;
    }
    std::sort(array, array + size);
    int n_zero = 0;
    int n_diff = 0;
    while (array[n_zero] == 0)
    {
        ++n_zero;
    }
    for (int i = n_zero + 1; i < size; ++i)
    {
        if (array[i] == array[i - 1])
        {
            return false;
        }
        if (array[i] - array[i - 1] > 1)
        {
            n_diff += array[i] - array[i - 1] - 1;
        }
    }
    return n_zero >= n_diff;
}

int main(int argc, char* argv[])
{
    {
        int array[] = {0,0,1,3,5};
        assert(isSequence(array, 5));
    }

    {
        int array[] = {1,0,4,5,6};
        assert(!isSequence(array, 5));
    }

    {
        int array[] = {1,4,2,5,6};
        assert(!isSequence(array, 5));
    }

    {
        int array[] = {1,2,0,1,4,};
        assert(!isSequence(array, 5));
    }

    {
        int array[] = {4,5,1,0,3};
        assert(!isSequence(NULL, 5));
        assert(!isSequence(array, 1));
        assert(!isSequence(array, -1));
    }

    printf("all test case passed!\n");
    return 0;
}
