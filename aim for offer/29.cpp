/*
数组中有一个数字出现的次数超过数组长度的一半，请找出
这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
*/

#include <stdexcept>
#include <stdio.h>

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// 用于快速排序的partition的划分不必以pivot（中值）严格划分，
// 即pivot可以包含在划分好的左右两半部分中，例如4,5,1,6,2,7,3,8以4为pivot划分，
// 对于快速排序3124|8576即可。
//
// 但是对于求类似于第k小元素partition，必须严格以pivot划分，即
// 如312|4|8576，4两旁的为划分的两半部分，但是4本身不能包含于划分的两半部分中。
//
//int partition(int* array, int begin, int end)
//{
//    int middle = (begin + end + 1) / 2;
//    while (true)
//    {
//        while (array[begin] < array[middle])
//        {
//            ++begin;
//        }
//        while (array[end] > array[middle])
//        {
//            --end;
//        }
//        if (begin >= end)
//        {
//            break;
//        }
//        swap(array[begin], array[end]);
//        ++begin;
//    }
//    return begin;
//}

//void qsort(int* array, int size)
//{
//    if (array == NULL || size <= 1)
//    {
//        return;
//    }
//    int middle = partition(array, size);
//    qsort(array, middle);
//    qsort(array + middle + 1, size - middle - 1);
//}

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

bool check(int* array, int size, int val)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == val)
        {
            ++count;
        }
    }
    if (count > size / 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int findnumberPartion(int* array, int size)
{
    if (array == NULL || size <= 0)
    {
        throw std::logic_error("invalid input");
    }
    if (size == 1)
    {
        return array[0];
    }
    int begin = 0;
    int end = size - 1;
    int index = partition(array, begin, end);
    while (index != size / 2)
    {
        if (index < size / 2)
        {
            begin = index + 1;
            index = partition(array, begin, end);
        }
        else
        {
            end = index - 1;
            index = partition(array, begin, end);
        }
    }
    if (check(array, size, array[index]))
    {
        return array[index];
    }
    else
    {
        throw std::logic_error("invalid input");
    }
}

int findNumberNoPartition(int* array, int size)
{
    if (array == NULL || size <= 0)
    {
        throw std::logic_error("invalid input");
    }
    int value;
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (count == 0)
        {
            value = array[i];
            ++count;
        }
        else
        {
            if (array[i] == value)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }
    }
    if (check(array, size, value))
    {
        return value;
    }
    else
    {
        throw std::logic_error("invalid input");
    }
}

int main(int argc, char* argv[])
{
    int array[] = {1,2,2,2,1,2,5,4,2};
    printf("%d\n", findnumberPartion(array, 9));
    printf("%d\n", findNumberNoPartition(array, 9));
    return 0;
}
