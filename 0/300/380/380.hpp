#pragma once
#include "leetcode.h"

class RandomizedSet 
{
public:
    /** Initialize your data structure here. */
    RandomizedSet() 
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        if (m_i.find(val) == m_i.end())
        {
            m_i[val] = m_n.size();
            m_n.push_back(val);
            return true;
        }
        else
        {
            return false;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        if (m_i.find(val) == m_i.end())
        {
            return false;
        }
        else
        {
            m_i[m_n.back()] = m_i[val];
            swap(m_n[m_i[val]], m_n.back());
            m_i.erase(val);
            m_n.pop_back();
            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom() 
    {
        return m_n[rand() % m_n.size()];
    }

private:
    unordered_map<int, int> m_i;
    vector<int> m_n;
};