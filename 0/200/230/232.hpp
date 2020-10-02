#pragma once
#include "leetcode.h"

class MyQueue 
{
public:
    /** Initialize your data structure here. */
    MyQueue() 
    {

    }

    /** Push element x to the back of queue. */
    void push(int x) 
    {
        stack<int> s;
        while (m_s.empty() == false)
        {
            s.push(m_s.top());
            m_s.pop();
        }

        m_s.push(x);
        while (s.empty() == false)
        {
            m_s.push(s.top());
            s.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        int res = m_s.top();
        m_s.pop();
        return res;
    }

    /** Get the front element. */
    int peek() 
    {
        return m_s.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return m_s.empty();
    }

private:
    stack<int> m_s;
};