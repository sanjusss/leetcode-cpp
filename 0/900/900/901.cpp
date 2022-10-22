/*
 * @Author: sanjusss
 * @Date: 2022-10-21 08:39:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-21 08:42:18
 * @FilePath: \0\900\900\901.cpp
 */
#include "leetcode.h"

class StockSpanner {
public:
    StockSpanner() {
        m_s.emplace(INT_MAX, 0);
    }
    
    int next(int price) {
        while (m_s.top().first <= price) {
            m_s.pop();
        }

        ++m_i;
        int ans = m_i - m_s.top().second;
        m_s.emplace(price, m_i);
        return ans;
    }

private:
    int m_i = 0;
    stack<pair<int, int>> m_s;
};
