/*
 * @Author: sanjusss
 * @Date: 2021-10-09 08:34:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-09 08:40:16
 * @FilePath: \0\300\350\352.cpp
 */
#include "leetcode.h"

class SummaryRanges {
public:
    SummaryRanges() {

    }
    
    void addNum(int val) {
        auto p = intervals.upper_bound(val);
        int b = val;
        int e = val;
        if (p != intervals.begin()) {
            auto last = prev(p);
            if (last->second >= val - 1) {
                b = last->first;
                e = max(last->second, e);
                intervals.erase(last);
            }
        }

        if (p != intervals.end()) {
            if (p->first == val + 1) {
                e = p->second;
                intervals.erase(p);
            }
        }

        intervals[b] = e;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto [b, e] : intervals) {
            res.push_back({ b, e });
        }

        return res;
    }

private:
    map<int, int> intervals;
};