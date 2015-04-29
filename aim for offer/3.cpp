/*
在一个二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样
的一个二维数组和整数，判断数组中是否含有该整数。

1  2  8  9
2  4  9  12
4  7  10 13
6  8  11 15
*/

#include <stdio.h>
#include <assert.h>

bool find1(int* array, int rows, int columns, int val)
{
    if (array == NULL)
    {
        return false;
    }
    int row = 0;
    int column = columns - 1;
    while (row < rows && column >= 0)
    {
        if (array[row * columns + column] == val)
        {
            return true;
        }
        else if (array[row * columns + column] > val)
        {
            --column;
        }
        else if (array[row* columns + column] < val)
        {
            ++row;
        }
    }
    return false;
}

bool find2(int* array, int rows, int columns, int val)
{
    if (array == NULL)
    {
        return false;
    }
    int row = rows - 1;
    int column = 0;
    while (row >= 0 && column < columns)
    {
        if (array[row * columns + column] == val)
        {
            return true;
        }
        else if (array[row * columns + column] > val)
        {
            --row;
        }
        else if (array[row * columns + column] < val)
        {
            ++column;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    int array[4][4] =
    {
        1, 2, 8, 9,
        2, 4, 9, 12,
        4, 7, 10, 13,
        6, 8, 11, 15,
    };

    assert(!find1(NULL, 4, 4, 6));
    assert(find1(&array[0][0], 4, 4, 6));
    assert(find1(&array[0][0], 4, 4, 7));
    assert(find1(&array[0][0], 4, 4, 11));
    assert(!find1(&array[0][0], 4, 4, 5));
    assert(!find1(&array[0][0], 4, 4, 3));

    assert(!find2(NULL, 4, 4, 6));
    assert(find2(&array[0][0], 4, 4, 6));
    assert(find2(&array[0][0], 4, 4, 7));
    assert(find2(&array[0][0], 4, 4, 11));
    assert(!find2(&array[0][0], 4, 4, 5));
    assert(!find2(&array[0][0], 4, 4, 3));
    return 0;
}
