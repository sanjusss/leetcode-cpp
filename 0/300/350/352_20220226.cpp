/*
 * @Author: sanjusss
 * @Date: 2022-02-26 17:46:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-26 18:10:24
 * @FilePath: \0\300\350\352_20220226.cpp
 */
#include "leetcode.h"

class SummaryRanges {
public:
    SummaryRanges() {

    }
    
    void addNum(int val) {
        auto next = m_intervals.lower_bound(val);
        auto prev = next == m_intervals.begin() ? m_intervals.end() : std::prev(next);
        int b = val;
        int e = val;
        if (next != m_intervals.end()) {
            if (next->first == b) {
                return;
            }
            else if (next->first == b + 1) {
                e = next->second;
                m_intervals.erase(next);
            }
        }

        if (prev == m_intervals.end() || prev->second < b - 1) {
            m_intervals.emplace(b, e);
        }
        else {
            prev->second = max(prev->second, e);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto [b, e] : m_intervals) {
            ans.push_back({ b, e });
        }

        return ans;
    }

private:
    map<int, int> m_intervals;
};