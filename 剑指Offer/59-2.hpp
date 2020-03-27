#pragma once
#include "leetcode.h"

class MaxQueue 
{
public:
    MaxQueue() 
    {

    }

    int max_value() 
    {
        if (m_q.empty())
        {
            return -1;
        }
        else
        {
            return m_d.front();
        }
    }

    void push_back(int value) 
    {
        m_q.push(value);
        while (m_d.empty() == false && m_d.back() < value)
        {
            m_d.pop_back();
        }

        m_d.push_back(value);
    }

    int pop_front() 
    {
        if (m_q.empty())
        {
            return -1;
        }
        else
        {
            int res = m_q.front();
            m_q.pop();
            if (m_d.front() == res)
            {
                m_d.pop_front();
            }

            return res;
        }
    }

private:
    queue<int> m_q;
    deque<int> m_d;
};
