#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <stdlib.h>
#include <stdio.h>

template<typename T>
struct Less
{
    bool operator()(const T& a, const T& b)
    {
        return a < b;
    }
};

template<typename T>
struct SkipListNode
{
    SkipListNode<T>*  next;
    SkipListNode<T>*  below;
    T                 value;

    SkipListNode()
        : next(NULL), below(NULL)
    {
    }
};

template<typename T>
struct SkipListIterator
{
public:
    typedef SkipListNode<T> Node;

    SkipListIterator(Node* p)
        : node_(p)
    {
    }

    T& operator*()
    {
        return node_->value;
    }

    const T& operator*() const
    {
        return node_->value;
    }

    T* operator->()
    {
        return &(node_->value);
    }

    const T* operator->() const
    {
        return &(node_->value);
    }

    SkipListIterator& operator++()
    {
        node_ = node_->next;
        return *this;
    }

    SkipListIterator operator++(int)
    {
        SkipListIterator tmp = *this;
        node_ = node_->next;
        return tmp;
    }

    Node* node_;
};

template<typename T>
inline bool operator==(const SkipListIterator<T>& lhs, const SkipListIterator<T>& rhs)
{
    return lhs.node_ == rhs.node_;
}

template<typename T>
inline bool operator!=(const SkipListIterator<T>& lhs, const SkipListIterator<T>& rhs)
{
    return !(lhs == rhs);
}

template<typename T>
struct SkipListConstIterator
{
public:
    typedef SkipListNode<T> Node;

    SkipListConstIterator(Node* p)
        : node_(p)
    {
    }

    T& operator*()
    {
        return node_->value;
    }

    const T& operator*() const
    {
        return node_->value;
    }

    T* operator->()
    {
        return &(node_->value);
    }

    const T* operator->() const
    {
        return &(node_->value);
    }

    SkipListConstIterator& operator++()
    {
        node_ = node_->next;
        return *this;
    }

    SkipListConstIterator operator++(int)
    {
        SkipListConstIterator tmp = *this;
        node_ = node_->next;
        return tmp;
    }

    const Node* node_;
};

template<typename T>
inline bool operator==(const SkipListConstIterator<T>& lhs, const SkipListConstIterator<T>& rhs)
{
    return lhs.node_ == rhs.node_;
}

template<typename T>
inline bool operator!=(const SkipListConstIterator<T>& lhs, const SkipListConstIterator<T>& rhs)
{
    return !(lhs == rhs);
}

template<typename T, typename Comp = Less<T> >
class SkipList
{
public:
    typedef SkipListNode<T>           Node;
    typedef SkipListIterator<T>       iterator;
    typedef SkipListConstIterator<T>  const_iterator;
    typedef size_t                    size_type;
    typedef T                         value_type;

    static const int kMaxLevel = 32;

    SkipList()
        : head_(new Node), root_(head_), level_(1), size_(0)
    {
        head_->next = new Node;
        root_end_ = root_->next;
    }

    ~SkipList()
    {
        for (Node* head = head_; head;)
        {
            for (Node* p = head->next; p;)
            {
                Node* deleter = p;
                p = p->next;
                delete deleter;
            }
            Node* tmp = head;
            head = head->below;
            delete tmp;
        }
    }

    size_type level() const
    {
        return level_;
    }

    size_type size() const
    {
        return size_;
    }

    iterator begin()
    {
        return iterator(root_->next);
    }

    const_iterator begin() const
    {
        return const_iterator(root_->next);
    }

    iterator end()
    {
        return iterator(root_end_);
    }

    const_iterator end() const
    {
        return const_iterator(root_end_);
    }

    void setInsertSrand(unsigned int seed)
    {
        srand(seed);
    }

    void insert(iterator pos)
    {
        insert(*pos);
    }

    void insert(const value_type& val)
    {
        size_type k = makeLevel();
        if (k <= level_)
        {
            insertNormal(k, val);
        }
        else
        {
            insertGreaterLevel(k, val);
        }
    }

    iterator find(const value_type& val)
    {
        Node* p = head_;
        while (p && p->next)
        {
            if (p->next->next != NULL)
            {
                if (compare_(p->next->value, val))
                {
                    p = p->next;
                }
                else
                {
                    if (compare_(val, p->next->value))
                    {
                        p = p->below;
                    }
                    else
                    {
                        return iterator(p->next);
                    }
                }
            }
            else
            {
                p = p->below;
            }
        }
        return iterator(end());
    }

    void erase(value_type val)
    {
        for (Node* head = head_; head; head = head->below)
        {
            for (Node* p = head; p->next; p = p->next)
            {
                if (p->next->value == val)
                {
                    Node* tmp = p->next;
                    p->next = tmp->next;
                    delete tmp;
                }
            }
        }
    }

    // for debug
    void print()
    {
        for (Node* head = head_; head; head = head->below)
        {
            for (Node* p = head->next; p->next; p = p->next)
            {
                printf("%d ", p->value);
            }
            printf("\n");
        }
    }

private:
    size_type makeLevel()
    {
        size_type k = 1;
        while (static_cast<double>(rand() & 0xffff) < 0.25 * 0xffff)
        {
            ++k;
        }
        return k < kMaxLevel ? k : kMaxLevel;
    }

    void insertNormal(value_type k, const value_type& val)
    {
        value_type step = level_ - k;
        Node* head = head_;
        for (value_type i = 0; i < step; ++i)
        {
            head = head->below;
        }
        Node* p = head;
        Node* prev = NULL;
        Node* current = p->next;
        bool insert_once = false;
        while (p && current)
        {
            while (current->next && compare_(current->value, val))
            {
                p = current;
                current = current->next;
            }
            if (current->next == NULL || compare_(val, current->value))
            {
                Node* node = new Node;
                node->value = val;
                node->next = current;
                p->next = node;
                if (prev)
                {
                    prev->below = node;
                }
                prev = node;
                p = p->below;
                if (p)
                {
                    current = p->next;
                }
                insert_once = true;
            }
            else
            {
                return;
            }
        }
        if (insert_once)
        {
            ++size_;
        }
    }

    void insertGreaterLevel(value_type k, const value_type& val)
    {
        value_type step = k - level_;
        level_ = k;
        for (int i = 0; i < step; ++i)
        {
            Node* p = new Node;
            p->next = new Node;
            p->below = head_;
            head_ = p;
        }
        Node* p = head_;
        Node* prev = NULL;
        Node* current = p->next;
        bool insert_once = false;
        while (p && current)
        {
            while (current->next && compare_(current->value, val))
            {
                p = current;
                current = current->next;
            }
            if (current->next == NULL || compare_(val, current->value))
            {
                Node* node = new Node;
                node->value = val;
                node->next = current;
                p->next = node;
                if (prev)
                {
                    prev->below = node;
                }
                prev = node;
                p = p->below;
                if (p)
                {
                    current = p->next;
                }
                insert_once = true;
            }
            else
            {
                return;
            }
        }
        if (insert_once)
        {
            ++size_;
        }
    }

    Node*      head_;
    Node*      root_;
    Node*      root_end_;
    size_type  level_;
    size_type  size_;
    Comp       compare_;
};

template<typename T, typename Comp>
const int SkipList<T, Comp>::kMaxLevel;

#endif
