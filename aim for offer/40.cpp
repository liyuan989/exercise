/*
一个整型数组里除了2个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度是O(N)，空间复杂度O(1)。
*/

// 原理: a ^ 0 = a, a ^ b ^ b = a, a ^ b ^ c ^ d ^ b ^ c ^ d = a

#include <stdio.h>

bool compare(int n, int bit_index)
{
    return n & (1 << bit_index);
}

int findFirstBitIsOne(int n)
{
    int index = 0;
    for (size_t i = 0; i < 8 * sizeof(int); ++i)
    {
        if (n & (1 << index))
        {
            break;
        }
        ++index;
    }
    return index;
}

void printTwoNumber(int* array, int size)
{
    if (array == NULL || size < 2)
    {
        return;
    }
    int val = 0;
    for (int i = 0; i < size; ++i)
    {
        val ^= array[i];
    }
    int bit_index = findFirstBitIsOne(val);
    if (static_cast<size_t>(bit_index) >= 8 * sizeof(int))
    {
        return;
    }
    int val1 = 0;
    int val2 = 0;
    for (int i = 0; i < size; ++i)
    {
        if (compare(array[i], bit_index))
        {
            val1 ^= array[i];
        }
        else
        {
            val2 ^= array[i];
        }
    }
    printf("%d %d\n", val1, val2);
}

int main(int argc, char* argv[])
{
    int array[] = {2,4,3,6,3,2,5,5};
    printTwoNumber(array, 8);
    return 0;
}
