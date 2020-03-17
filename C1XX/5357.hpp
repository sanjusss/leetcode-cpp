#pragma once
#include "leetcode.h"

class CustomStack 
{
public:
    CustomStack(int maxSize) 
    {
        m_max = maxSize;
    }

    void push(int x) 
    {
        if (m_q.size() < m_max)
        {
            m_q.push_back(x);
        }
    }

    int pop() 
    {
        if (m_q.empty())
        {
            return -1;
        }
        else
        {
            int res = m_q.back();
            m_q.pop_back();
            return res;
        }
    }

    void increment(int k, int val) 
    {
        auto i = m_q.begin();
        int j = 0;
        while (i != m_q.end() && j < k)
        {
            *i += val;
            ++i;
            ++j;
        }
    }

private:
    deque<int> m_q;
    int m_max;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */