#pragma once
#include "leetcode.h"

class MinStack 
{
public:
    /** initialize your data structure here. */
    MinStack() 
    {

    }

    void push(int x) 
    {
        m_set.insert(x);
        m_stack.push(x);
    }

    void pop() 
    {
        m_set.erase(m_set.find(m_stack.top()));
        m_stack.pop();
    }

    int top() 
    {
        return m_stack.top();
    }

    int getMin() 
    {
        return *m_set.begin();
    }

private:
    multiset<int> m_set;
    stack<int> m_stack;
};