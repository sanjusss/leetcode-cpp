#pragma once
#include "leetcode.h"

class MyStack 
{
public:
    /** Initialize your data structure here. */
    MyStack() 
    {

    }

    /** Push element x onto stack. */
    void push(int x) 
    {
        queue<int> q;
        q.push(x);
        while (m_q.empty() == false)
        {
            q.push(m_q.front());
            m_q.pop();
        }
        
        m_q.swap(q);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int res = m_q.front();
        m_q.pop();
        return res;
    }

    /** Get the top element. */
    int top() 
    {
        return m_q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return m_q.empty();
    }

private:
    queue<int> m_q;
};
