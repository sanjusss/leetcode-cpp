#pragma once
#include "leetcode.h"

class MovingAverage 
{
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : m_maxSize(size) 
    {
        
    }

    double next(int val) 
    {
        m_queue.push(val);
        sum += val;
        if (m_queue.size() > m_maxSize) 
        {
            sum -= m_queue.front();
            m_queue.pop();
        }

        return (double)sum / (double)m_queue.size();
    }

private:
    const int m_maxSize;
    queue<int> m_queue;
    int sum = 0;
};
