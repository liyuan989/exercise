/*
求1+2+...+n，要求不能使用乘除法、for、while、if、else、else if、swith、case等
关键字以及条件判断语句(a ? b : c)。
*/

#include <stdio.h>

// 利用虚函数求解

class SolveBase;

SolveBase* g_virtualFunc[2];

class SolveBase
{
public:
    virtual ~SolveBase()
    {
    }

    virtual int sum(int n)
    {
        return 0;
    }
};

class Solve : public SolveBase
{
public:
    virtual ~Solve()
    {
    }

    virtual int sum(int n)
    {
        return g_virtualFunc[!!n]->sum(n - 1) + n;
    }
};

int sumByVirtualFunc(int n)
{
    SolveBase base;
    Solve solve;
    g_virtualFunc[0] = &base;
    g_virtualFunc[1] = &solve;
    return solve.sum(n);
}

// 利用函数指针求解

typedef int (*Func)(int);

Func g_func[2];

int sumFuncBase(int n)
{
    return 0;
}

int sumFunc(int n)
{
    return g_func[!!n](n - 1) + n;
}

int sumByFunc(int n)
{
    g_func[0] = sumFuncBase;
    g_func[1] = sumFunc;
    return sumFunc(n);
}

// 利用模板元编程求解

template<int N>
struct Sum
{
    static const int value = Sum<N - 1>::value + N;
};

template<int N>
const int Sum<N>::value;

template<>
struct Sum<1>
{
    static const int value = 1;
};

const int Sum<1>::value;

int main(int argc, char* argv[])
{
    printf("%d %d %d\n", sumByVirtualFunc(100), sumByFunc(100), Sum<100>::value);
    return 0;
}
