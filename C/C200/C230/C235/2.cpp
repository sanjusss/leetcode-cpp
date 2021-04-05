/*
 * @Author: sanjusss
 * @Date: 2021-04-04 10:29:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-04 10:38:07
 * @FilePath: \C\C200\C230\C235\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k);
        unordered_map<int, unordered_set<int>> users;
        for (auto& log : logs) {
            users[log[0]].insert(log[1]);
        }

        for (auto& [_, mins] : users) {
            ++ans[mins.size() - 1];
        }

        return ans;
    }
};