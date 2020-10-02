#pragma once
#include "leetcode.h"

class TwoSum 
{
public:
    /** Initialize your data structure here. */
    TwoSum() 
    {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) 
    {
        ++m_n[number];
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) 
    {
        auto end = m_n.upper_bound(value / 2);
        for (auto i = m_n.begin(); i != end; ++i)
        {
            int b = value - i->first;
            if (i->first == b)
            {
                if (i->second >= 2)
                {
                    return true;
                }
            }
            else
            {
                if (m_n.find(b) != m_n.end())
                {
                    return true;
                }
            }
        }

        return false;
    }

private:
    map<int, int> m_n;
};
