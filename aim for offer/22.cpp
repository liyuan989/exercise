/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列
是否为该栈的弹出序列。假设压入栈的所有数字均不相等。例如序列
1、2、3、4、5是某栈的压入序列，序列4、5、3、2、1是该压栈序列
对应的一个弹出序列，但4、3、5、1、2就不可能是该栈序列的弹出序列。
 */

#include <stack>
#include <assert.h>
#include <stdio.h>

bool isPopOrder(int* push, int* pop, int size)
{
    if (push == NULL || pop == NULL || size <= 0)
    {
        return false;
    }
    std::stack<int> stack;
    int n_push = 0;
    int n_pop = 0;
    while (n_pop < size)
    {
        while (stack.empty() || stack.top() != pop[n_pop])
        {
            if (n_push == size)
            {
                break;
            }
            stack.push(push[n_push]);
            ++n_push;
        }
        if (stack.top() != pop[n_pop])
        {
            return false;
        }
        else
        {
            stack.pop();
            ++n_pop;
        }
    }
    if (stack.empty() && n_push == size && n_pop == size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char* argv[])
{
    int push[] = {1, 2, 3, 4, 5};
    int pop1[] = {4, 5, 3, 2, 1};
    int pop2[] = {4, 3, 5 ,1, 2};
    assert(isPopOrder(push, pop1, 5));
    assert(!isPopOrder(push, pop2, 5));
    return 0;
}
