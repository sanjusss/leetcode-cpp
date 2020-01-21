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
        return *m_nums.begin();
    }

private:
    void addNum(int val)
    {
        if (m_nums.size() < m_k)
        {
            m_nums.insert(val);
        }
        else if (val > * m_nums.begin())
        {
            m_nums.erase(m_nums.begin());
            m_nums.insert(val);
        }
    }

    int m_k;
    multiset<int> m_nums;
};
