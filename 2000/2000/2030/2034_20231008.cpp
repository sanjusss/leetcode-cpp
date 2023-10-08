/*
 * @Author: sanjusss
 * @Date: 2023-10-08 07:48:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-10-08 07:55:31
 * @FilePath: \2000\2000\2030\2034_20231008.cpp
 */
#include "leetcode.h"

class StockPrice {
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        m_t2p[timestamp] = price;
        m_maxs.emplace(price, timestamp);
        m_mins.emplace(price, timestamp);
        m_latest = max(m_latest, timestamp);
    }
    
    int current() {
        return m_t2p[m_latest];
    }
    
    int maximum() {
        while (m_t2p[m_maxs.top().second] != m_maxs.top().first) {
            m_maxs.pop();
        }

        return m_maxs.top().first;
    }
    
    int minimum() {
        while (m_t2p[m_mins.top().second] != m_mins.top().first) {
            m_mins.pop();
        }

        return m_mins.top().first;
    }

private:
    unordered_map<int, int> m_t2p;
    priority_queue<pair<int, int>> m_maxs;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> m_mins;
    int m_latest = 0;
};