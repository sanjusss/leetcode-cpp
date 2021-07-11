/*
 * @Author: sanjusss
 * @Date: 2021-07-10 15:11:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-10 15:18:53
 * @FilePath: \0\900\980\981.cpp
 */
#include "leetcode.h"

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m_values[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto kp = m_values.find(key);
        if (kp == m_values.end()) {
            return ""s;
        }

        const auto& values = kp->second;
        auto vp = values.upper_bound(timestamp);
        if (vp == values.begin()) {
            return ""s;
        }
        else {
            return prev(vp)->second;
        }
    }

private:
    unordered_map<string, map<int, string>> m_values;
};