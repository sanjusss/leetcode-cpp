#pragma once
#include "leetcode.h"

class KthLargest 
{
public:
    KthLargest(int k, vector<int>& nums) :
        m_k(k)
    {
        for (auto i : nums)
        {
            addNum(i);
        }
    }

    int add(int val) 
    {
        addNum(val);
        return m_q.top();
    }

private:
    void addNum(int val)
    {
        if (m_size < m_k)
        {
            m_q.push(val);
            ++m_size;
        }
        else if (val > m_q.top())
        {
            m_q.pop();
            m_q.push(val);
        }
    }

    int m_k;
    int m_size = 0;
    priority_queue<int, vector<int>, greater<int>> m_q;
};
