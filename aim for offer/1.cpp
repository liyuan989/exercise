/*
如下为类型CMyString的声明，请为该类添加赋值运算符函数。
class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString();

private:
    char* m_pData;
};
*/

#include <stdio.h>
#include <algorithm>

class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString();

    // swap-and-copy idom
    void swap(CMyString& str)
    {
        std::swap(m_pData, str.m_pData);
    }

    CMyString& operator=(CMyString rhs)
    {
        swap(rhs);
        return *this;
    }

    /* 如果面试官知识比较老旧，认为赋值操作符一定要以const reference为参数，
       可用这种方案，不过最好的方案是pass by value。
       详见http://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
    CMyString& operator=(const CMyString& rhs)
    {
        CMyString tmp(rhs);
        swap(tmp);
        return *this;
    }
    */

private:
    char* m_pData;
};
