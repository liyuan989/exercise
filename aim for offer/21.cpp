/*
定义栈的数据结构，请在该类型中实现一个能够得到栈最小
元素的min函数。在该栈中，调用min，push，pop，top的时间
复杂度都是O(1)。
 */

#include <stack>
#include <assert.h>
#include <stdio.h>

template<typename T>
class Stack
{
public:
    void push(const T& val)
    {
        if (min_.empty())
        {
            assert(data_.empty());
            min_.push(val);
        }
        else
        {
            if (val < min_.top())
            {
                min_.push(val);
            }
            else
            {
                min_.push(min_.top());
            }
        }
        data_.push(val);
    }

    void pop()
    {
        assert(!data_.empty());
        assert(!min_.empty());
        data_.pop();
        min_.pop();
    }

    T& min()
    {
        assert(!data_.empty());
        assert(!min_.empty());
        return min_.top();
    }

    const T& min() const
    {
        assert(!data_.empty());
        assert(!min_.empty());
        return min_.top();
    }

    T& top()
    {
        assert(!data_.empty());
        assert(!min_.empty());
        return data_.top();
    }

    const T& top() const
    {
        assert(!data_.empty());
        assert(!min_.empty());
        return data_.top();
    }

private:
    std::stack<T>  data_;
    std::stack<T>  min_;
};

int main(int argc, char* argv[])
{
    Stack<int> stack;
    stack.push(9);
    assert(stack.top() == stack.min());
    assert(stack.min() == 9);

    stack.push(10);
    assert(stack.min() == 9);

    stack.push(7);
    assert(stack.min() == 7);

    stack.push(8);
    assert(stack.min() == 7);

    stack.push(11);
    assert(stack.min() == 7);

    stack.pop();
    assert(stack.min() == 7);

    stack.pop();
    assert(stack.min() == 7);

    stack.pop();
    assert(stack.min() == 9);
    return 0;
}
