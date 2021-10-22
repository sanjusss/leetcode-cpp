/*
 * @Author: sanjusss
 * @Date: 2021-10-10 10:25:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-10 11:17:35
 * @FilePath: \C\C200\C260\C262\3.cpp
 */
#include "leetcode.h"

class StockPrice {
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        if (t2p.count(timestamp)) {
            prices.erase(prices.find(t2p[timestamp]));
        }

        t2p[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return t2p.rbegin()->second;
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }

private:
    map<int, int> t2p;
    multiset<int> prices;
};