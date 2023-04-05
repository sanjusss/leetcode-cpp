/*
 * @Author: sanjusss
 * @Date: 2023-04-02 10:28:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-02 10:37:04
 * @FilePath: \C\C300\C330\C339\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i : nums) {
            ++cnt[i];
        }

        queue<pair<int,int>> q;
        for (auto& [i, c] : cnt) {
            q.emplace(i, c);
        }

        vector<vector<int>> ans;
        while (!q.empty()) {
            auto& row = ans.emplace_back();
            for (int qi = q.size(); qi > 0; --qi) {
                auto [i, c] = q.front();
                q.pop();
                row.emplace_back(i);
                if (--c > 0) {
                    q.emplace(i, c);
                }
            } 
        }

        return ans;
    }
};