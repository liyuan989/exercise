/*
输入一个字符串，打印出该字符串中字符的所有排列。
例如输入字符abc，则打印出由字符a、b、c所能排列
出来的所有字符串abc、acb、bac、bca、cba。
*/

#include <utility>
#include <stack>
#include <stdio.h>

void swap(char& a, char& b)
{
    if (a == b)
    {
        return;
    }
    char tmp = a;
    a = b;
    b = tmp;
}

void print(char* str, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void doPermutation(char* str, int index, int size)
{
    if (index == size - 1)
    {
        print(str, size);
        return;
    }
    for (int i = index; i < size; ++i)
    {
        swap(str[index], str[i]);
        doPermutation(str, index + 1, size);
        swap(str[index], str[i]);
    }
}

void permutation(char* str, int size)
{
    if (str == NULL || size <= 0)
    {
        return;
    }
    doPermutation(str, 0, size);
}

/*

将全排列递归转换为非递归的思路基本为手工维护栈，把原本
递归时所需的状态压入栈中保存起来，用的时候再弹栈。
整个递归的过程可以看成变量一颗树，只在遍历到叶子结点的时候打印该字符串。

            root
        /     |     \
       A      B      C
      / \    / \    / \
     B   C  A   C  A   B
     |   |  |   |  |   |
     C   B  C   A  B   A

*/

void doPermutationLoop(char* str, int size)
{
    std::stack<std::pair<int, int> > stack;  // pair<i,index)>
    for (int i = 0; i < size; ++i)
    {
        stack.push(std::make_pair(i, i));
    }
    while (!stack.empty())
    {
        int index = stack.top().second;
        if (index == size - 1)
        {
            print(str, size);
            stack.pop();
        }
        while (!stack.empty() && stack.top().first == size - 1)
        {
            swap(str[stack.top().second], str[stack.top().first]);
            stack.pop();
        }
        if (stack.empty())
        {
            break;
        }
        else
        {
            int n = stack.top().first + 1;
            swap(str[stack.top().second], str[n]);
            ++stack.top().first;
            for (int i = stack.top().second + 1; i < size; ++i)
            {
                stack.push(std::make_pair(i, i));
            }
        }
    }
}

void permutationLoop(char* str, int size)
{
    if (str == NULL || size <= 0)
    {
        return;
    }
    doPermutationLoop(str, size);
}

int main(int argc, char* argv[])
{
    char str[] = "abc";
    permutation(NULL, 1);
    permutation(str, 0);
    permutation(str, 3);

    printf("\n");

    permutationLoop(NULL, 1);
    permutationLoop(str, 0);
    permutationLoop(str, 3);
    return 0;
}
