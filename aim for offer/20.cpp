/*
输入一个矩阵，按照向外向里以顺时针的顺序依次打印每一个数字。
例如：如果输入以下矩阵
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
则依次打印出数字1、2、3、4、8、12、16、15、14、13、9、5、6、
7、11、10。
 */

#include <stdio.h>

void printOneCircle(int** matrix, int row, int column, int start)
{
    int end_row = row - start;
    int end_colomn = column - start;
    for (int i = start; i < end_colomn; ++i)
    {
        printf("%d ", matrix[start][i]);
    }

    if (end_row - 1 > start)
    {
        for (int i = start + 1; i < end_row; ++i)
        {
            printf("%d ", matrix[i][end_colomn - 1]);
        }
    }

    if (end_row - 1 > start && column - 1 > start)
    {
        for (int i = end_colomn - 2; i >= start; --i)
        {
            printf("%d ", matrix[end_row - 1][i]);
        }
    }

    if (end_row - 2 > start && column - 1 > start)
    {
        for (int i = end_row - 2; i > start; --i)
        {
            printf("%d ", matrix[i][start]);
        }
    }
}

void printClockwise(int** matrix, int row, int column)
{
    if (matrix == NULL || row <= 0 || column <= 0)
    {
        return;
    }
    int start = 0;
    while (row > 2 * start && column > 2 * start)
    {
        printOneCircle(matrix, row, column, start);
        ++start;
    }
}

int main(int argc, char* argv[])
{
    {
        int a1[] = {1, 2, 3, 4};
        int a2[] = {5, 6, 7, 8};
        int a3[] = {9, 10, 11, 12};
        int a4[] = {13, 14, 15, 16};
        int* matrix[] = {a1, a2, a3, a4};
        printClockwise(matrix, 4, 4);
        printf("\n");
    }

    {
        int a1[] = {1, 2, 3};
        int a2[] = {4, 5, 6};
        int a3[] = {7, 8, 9};
        int* matrix[] = {a1, a2, a3};
        printClockwise(matrix, 3, 3);
        printf("\n");
    }

    {
        int a1[] = {1, 2};
        int a2[] = {3, 4};
        int* matrix[] = {a1, a2};
        printClockwise(matrix, 2, 2);
        printf("\n");
    }

    {
        int a1[] = {1, 2};
        int* matrix[] = {a1};
        printClockwise(matrix, 1, 2);
        printf("\n");
    }

    {
        int a1[] = {1};
        int a2[] = {2};
        int* matrix[] = {a1, a2};
        printClockwise(matrix, 2, 1);
        printf("\n");
    }

    {
        int a1[] = {1};
        int a2[] = {2};
        int a3[] = {3};
        int* matrix[] = {a1, a2, a3};
        printClockwise(matrix, 3, 1);
        printf("\n");
    }

    {
        int a1[] = {1};
        int* matrix[] = {a1};
        printClockwise(matrix, 1, 1);
        printf("\n");
    }

    {
        int a1[] = {1};
        int* matrix[] = {a1};
        printClockwise(NULL, 4, 3);
        printClockwise(matrix, 0, -1);
        printClockwise(matrix, -1, 0);
        printClockwise(NULL, 0, 0);
        printClockwise(NULL, -1, -1);
    }

    return 0;
}
