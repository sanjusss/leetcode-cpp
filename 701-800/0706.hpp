#pragma once
#include "leetcode.h"

class MyHashMap 
{
public:
    /** Initialize your data structure here. */
    MyHashMap() 
    {

    }

    /** value will always be non-negative. */
    void put(int key, int value) 
    {
        auto pos = lower_bound(m_keys.cbegin(), m_keys.cend(), key);
        if (pos == m_keys.cend())
        {
            m_keys.push_back(key);
            m_values.push_back(value);
        }
        else if (*pos == key)
        {
            *next(m_values.begin(), distance(m_keys.cbegin(), pos)) = value;
        }
        else
        {
            m_values.insert(next(m_values.cbegin(), distance(m_keys.cbegin(), pos)), value);
            m_keys.insert(pos, key);
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        auto pos = lower_bound(m_keys.cbegin(), m_keys.cend(), key);
        if (pos != m_keys.cend() && *pos == key)
        {
           return *next(m_values.cbegin(), distance(m_keys.cbegin(), pos));
        }
        else
        {
            return -1;
        }
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) 
    {
        auto pos = lower_bound(m_keys.cbegin(), m_keys.cend(), key);
        if (pos != m_keys.cend() && *pos == key)
        {
            m_values.erase(next(m_values.cbegin(), distance(m_keys.cbegin(), pos)));
            m_keys.erase(pos);
        }
    }

private:
    vector<int> m_keys;
    vector<int> m_values;
};