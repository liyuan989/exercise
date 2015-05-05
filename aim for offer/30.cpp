/*
输入n个整数，找出其中最小的k个数。例如4、5、1、6、2、7、3、8
这8个数，最小的4个数是1、2、3、4。
*/

#include <set>
#include <stdio.h>

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int* array, int begin, int end)
{
    if (array == NULL || begin >= end)
    {
        return begin;
    }
    int middle = (begin + end + 1) / 2;
    int val = array[middle];
    array[middle] = array[end];
    while (begin < end)
    {
        while (begin < end && array[begin] <= val)
        {
            ++begin;
        }
        array[end] = array[begin];
        while (begin < end && array[end] >= val)
        {
            --end;
        }
        array[begin] = array[end];
    }
    array[begin] = val;
    return begin;
}

void getLeastNumbersPartition(int* input, int size, int* output, int k)
{
    if (input == NULL || size <= 0 || output == 0 || k <= 0 || k > size)
    {
        return;
    }
    int begin = 0;
    int end = size - 1;
    int index = partition(input, begin, end);
    while (index != k)
    {
        if (index < k)
        {
            begin = index + 1;
            index = partition(input, begin, end);
        }
        else
        {
            end = index - 1;
            index = partition(input, begin, end);
        }
    }
    for (int i = 0; i < k; ++i)
    {
        output[i] = input[i];
    }
}

void getLeastNumbersBinaryTree(int* input, int size, int* output, int k)
{
    if (input == NULL || size <= 0 || output == NULL || k <= 0 || k > size)
    {
        return;
    }
    std::multiset<int> tree;
    for (int i = 0; i < size; ++i)
    {
        if (tree.size() == static_cast<size_t>(k))
        {
            int max = *tree.rbegin();
            if (input[i] < max)
            {
                tree.erase(max);
                tree.insert(input[i]);
            }
        }
        else
        {
            tree.insert(input[i]);
        }
    }
    std::multiset<int>::iterator it = tree.begin();
    for (int i = 0; i < k; ++i)
    {
        output[i] = *it;
        ++it;
    }
}

int main(int argc, char* argv[])
{
    {
        int array[] = {4,5,1,6,1,7,3,8};
        int min[4];
        getLeastNumbersPartition(array, 8, min, 4);
        for (int i = 0; i < 4; ++i)
        {
            printf("%d ", min[i]);
        }
        printf("\n");
    }

    {
        int array[] = {4,5,1,6,1,7,3,8};
        int min[4];
        getLeastNumbersBinaryTree(array, 8, min, 4);
        for (int i = 0; i < 4; ++i)
        {
            printf("%d ", min[i]);
        }
        printf("\n");
    }
    return 0;
}
