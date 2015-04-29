/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数
appendTail和deleteHead，分别完成在队列尾部插入节点和在队列头部
删除节点的功能

template<typename T>
class CQueue
{
public:
    CQueue();
    ~CQueue();

    void appendTail(const T& node);
    T deleteHead();

private:
    std::statck<T> stack1;
    std::statck<T> stack2;
};
*/

#include <stack>
#include <stdexcept>
#include <stdio.h>

template<typename T>
class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(const T& val)
    {
        stack1_.push(val);
    }

    T deleteHead()
    {
        if (stack2_.empty())
        {
            while (!stack1_.empty())
            {
                stack2_.push(stack1_.top());
                stack1_.pop();
            }
        }
        if (stack2_.empty())
        {
            throw std::logic_error("queue is empty");
        }
        T val = stack2_.top();
        stack2_.pop();
        return val;
    }

private:
    std::stack<T>  stack1_;
    std::stack<T>  stack2_;
};

int main(int argc, char* argv[])
{
    CQueue<int> queue;
    for (int i = 0; i < 10; ++i)
    {
        queue.appendTail(i);
    }
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", queue.deleteHead());
    }
    return 0;
}
