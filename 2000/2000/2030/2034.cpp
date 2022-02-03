/*
 * @Author: sanjusss
 * @Date: 2022-01-23 11:09:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-23 11:18:57
 * @FilePath: \2000\2000\2030\2034.cpp
 */
#include "leetcode.h"

class StockPrice {
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        m_current = max(m_current, timestamp);
        if (m_t2p.count(timestamp)) {
            int old = m_t2p[timestamp];
            m_prices.erase(m_prices.find(old));
        }

        m_t2p[timestamp] = price;
        m_prices.insert(price);
    }
    
    int current() {
        return m_t2p[m_current];
    }
    
    int maximum() {
        return *m_prices.rbegin();
    }
    
    int minimum() {
        return *m_prices.begin();
    }

private:
    multiset<int> m_prices;
    unordered_map<int, int> m_t2p;
    int m_current = INT_MIN;
};
