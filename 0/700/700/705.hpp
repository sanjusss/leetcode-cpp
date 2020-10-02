#pragma once
#include "leetcode.h"

class MyHashSet 
{
public:
    /** Initialize your data structure here. */
    MyHashSet() 
    {

    }

    void add(int key) 
    {
        auto pos = lower_bound(m_vs.cbegin(), m_vs.cend(), key);
        if (pos == m_vs.cend())
        {
            m_vs.push_back(key);
        }
        else if (*pos != key)
        {
            m_vs.insert(pos, key);
        }
    }

    void remove(int key)
    {
        auto pos = lower_bound(m_vs.cbegin(), m_vs.cend(), key);
        if (pos != m_vs.cend() && *pos == key)
        {
            m_vs.erase(pos);
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) 
    {
        return binary_search(m_vs.cbegin(), m_vs.cend(), key);
    }

private:
    vector<int> m_vs;
};
