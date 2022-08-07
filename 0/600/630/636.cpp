/*
 * @Author: sanjusss
 * @Date: 2022-08-07 11:26:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-07 11:40:07
 * @FilePath: \0\600\630\636.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        vector<tuple<int, int, int>> times;  // 时间，（开始0， 结束1），标识
        for (auto& s : logs) {
            auto p1 = s.find(':');
            auto p2 = s.find(':', p1 + 1);
            times.emplace_back(stoi(s.substr(p2 + 1)), p2 - p1 == 4 ? 1 : 0, stoi(s.substr(0, p1)));
        }

        sort(times.begin(), times.end());
        int lastStart = 0;
        stack<int> funs;
        for (auto [time, isEnd, i] : times) {
            if (isEnd == 0) {
                if (!funs.empty()) {
                    ans[funs.top()] += time - lastStart;
                }

                lastStart = time;
                funs.push(i);
            }
            else {
                ans[funs.top()] += time + 1 - lastStart;
                funs.pop();
                lastStart = time + 1;
            }
        }

        return ans;
    }
};