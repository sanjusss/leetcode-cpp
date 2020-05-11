#pragma once
#include "leetcode.h"

//class MinStack 
//{
//public:
//    /** initialize your data structure here. */
//    MinStack() 
//    {
//
//    }
//
//    void push(int x) 
//    {
//        m_set.insert(x);
//        m_stack.push(x);
//    }
//
//    void pop() 
//    {
//        m_set.erase(m_set.find(m_stack.top()));
//        m_stack.pop();
//    }
//
//    int top() 
//    {
//        return m_stack.top();
//    }
//
//    int getMin() 
//    {
//        return *m_set.begin();
//    }
//
//private:
//    multiset<int> m_set;
//    stack<int> m_stack;
//};

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
        m_mins.push(INT_MAX);
    }

    void push(int x)
    {
        m_stack.push(x);
        if (m_mins.top() >= x)
        {
            m_mins.push(x);
        }
    }

    void pop()
    {
        if (m_stack.top() == m_mins.top())
        {
            m_mins.pop();
        }

        m_stack.pop();
    }

    int top()
    {
        return m_stack.top();
    }

    int getMin()
    {
        return m_mins.top();
    }

private:
    stack<int> m_mins;
    stack<int> m_stack;
};