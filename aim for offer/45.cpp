/*  约瑟夫(Josephuse)环问题
0,1,...,n-1这n个数字排成一个圆圈，从数字0开始
每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下
的最后一个数字。
*/

#include <stdexcept>
#include <list>
#include <assert.h>
#include <stdio.h>

int getLastNumber(int n, int m)
{
    if (n <= 0 || m <= 0)
    {
        throw std::logic_error("Invalid input");
    }
    std::list<int> circle;
    for (int i = 0; i < n; ++i)
    {
        circle.push_back(i);
    }
    std::list<int>::iterator it = circle.begin();
    while (circle.size() > 1)
    {
        for (int i = 1; i < m; ++i)
        {
            ++it;
            if (it == circle.end())
            {
                it = circle.begin();
            }
        }
        std::list<int>::iterator deleter = it;
        ++it;
        if (it == circle.end())
        {
            it = circle.begin();
        }
        circle.erase(deleter);
    }
    return circle.front();
}

// 原理: f(n) = (f(n-1) + m) % n
int getLastNumberEfficient(int n, int m)
{
    if (n <= 0 || m <= 0)
    {
        throw std::logic_error("Ivalid input");
    }
    int last = 0;
    for (int i = 2; i <= n; ++i)
    {
        last = (last + m) % i;
    }
    return last;
}

int main(int argc, char* argv[])
{
    assert(getLastNumber(5, 2) == 2);
    assert(getLastNumberEfficient(5, 2) == 2);
    assert(getLastNumber(4000, 3997) == getLastNumberEfficient(4000, 3997));
    assert(getLastNumber(10, 15) == getLastNumberEfficient(10, 15));
    printf("all test case passed!\n");
    return 0;
}
