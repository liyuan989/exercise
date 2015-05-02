/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历
的结果。如果是返回true，否则返回false。假设输入的数组
的任意两个数字都互不相同。
 */

#include <stdio.h>
#include <assert.h>

bool isPostOrder(int* array, int size)
{
    if (array == NULL || size <= 0)
    {
        return false;
    }
    if (size == 1)
    {
        return true;
    }
    int root = array[size - 1];
    int right = 0;
    while (right < size - 1 && array[right] < root)
    {
        ++right;
    }
    for (int i = right; i < size - 1; ++i)
    {
        if (array[i] < root)
        {
            return false;
        }
    }
    if (right == 0 || right == size - 1)
    {
        return isPostOrder(array, size - 1);
    }
    else
    {
        return isPostOrder(array, right) && isPostOrder(array + right, size - right - 1);
    }

}

int main(int argc, char* argv[])
{
    {
        int array[] = {5, 7, 6, 9, 11, 10, 8};
        assert(isPostOrder(array, 7));
    }

    {
        int array[] = {7, 4, 6, 5};
        assert(!isPostOrder(array, 4));
    }

    {
        int array[] = {1};
        assert(isPostOrder(array, 1));
    }

    {
        int array[] = {1};
        assert(!isPostOrder(array, 0));
    }

    {
        assert(!isPostOrder(NULL, 1));
        assert(!isPostOrder(NULL, -1));
    }

    printf("all test case passed!\n");
    return 0;
}
