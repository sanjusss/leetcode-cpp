/*
 * @Author: sanjusss
 * @Date: 2022-05-06 09:01:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-06 09:02:36
 * @FilePath: \0\900\930\933.cpp
 */
#include "leetcode.h"

class RecentCounter {
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        m_times.push(t);
        while (m_times.front() < t - 3000) {
            m_times.pop();
        }

        return m_times.size();
    }

private:
    queue<int> m_times;
};
