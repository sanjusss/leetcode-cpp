/*
 * @Author: sanjusss
 * @Date: 2022-07-16 11:01:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-16 11:03:57
 * @FilePath: \jianzhioffer2\041.cpp
 */
#include "leetcode.h"

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : m_maxSize(size) {

    }
    
    double next(int val) {
        m_sum += val;
        m_q.push(val);
        if (m_q.size() > m_maxSize) {
            m_sum -= m_q.front();
            m_q.pop();
        }

        return (double)m_sum / (double)m_q.size();
    }

private:
    int m_maxSize;
    int m_sum = 0;
    queue<int> m_q;
};