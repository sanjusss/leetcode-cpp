/*
 * @Author: sanjusss
 * @Date: 2023-10-15 10:38:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-12 10:44:05
 * @FilePath: \C\C300\C370\C371\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_set<string> ans;
        unordered_map<string, queue<int>> qs;
        sort(access_times.begin(), access_times.end());
        for (auto &times : access_times) {
            auto& name = times[0];
            auto& t24 = times[1];
            int t = ((t24[0] - '0') * 10 + (t24[1] - '0')) * 60 + ((t24[2] - '0') * 10 + (t24[3] - '0'));
            auto& q = qs[name];
            q.push(t);
            while (t - q.front() >= 60) {
                q.pop();
            }

            if (q.size() >= 3) {
                ans.insert(name);
            }
        }

        return { ans.begin(), ans.end() };
    }
};