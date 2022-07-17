/*
 * @Author: sanjusss
 * @Date: 2022-07-17 10:22:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-17 10:26:17
 * @FilePath: \0\300\360\362.cpp
 */
#include "leetcode.h"

class HitCounter {
public:
    HitCounter() {
    }

    void hit(int timestamp) {
        m_hits.push_back(timestamp);
    }

    int getHits(int timestamp) {
        return upper_bound(m_hits.begin(), m_hits.end(), timestamp) -
               upper_bound(m_hits.begin(), m_hits.end(), timestamp - 300);
    }

private:
    vector<int> m_hits;
};
