/*
 * @Author: sanjusss
 * @Date: 2023-01-20 17:23:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-20 17:26:26
 * @FilePath: \1000\1800\1810\1817.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> actives;
        for (auto& l : logs) {
            actives[l[0]].insert(l[1]);
        }

        vector<int> ans(k);
        for (auto& [_, s] : actives) {
            if (s.size() <= k) {
                ++ans[s.size() - 1];
            }
        }

        return ans;
    }
};