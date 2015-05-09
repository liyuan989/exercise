/*
用C++设计一个不能被继承的类
*/

// 方法一：将构造函数和析构函数都设为私有(缺点是不能正常创建该类的对象)

class NonDerived
{
private:
    NonDerived()
    {
    }

    ~NonDerived()
    {
    }

};

// 方法二：利用虚拟继承(优点是可以正常创建该类对象)

// 由于C++11之前的标准不允许直接设置friend parameter，即friend T。
// 所以需要利用type trait来完成。

template<typename T>
struct tag
{
    typedef T Type;
};

template<typename T>
class Base
{
private:
    friend class tag<T>::Type;

    Base()
    {
    }

    ~Base()
    {
    }
};

/*
对于C++11，可以直接设置template parameter，所以可以简化成这样：

template<typename T>
class Base
{
private:
    friend T;

    Base()
    {

    }

    ~Base()
    {

    }
};
*/

class NonDerived : virtual public Base<NonDerived>
{
};
