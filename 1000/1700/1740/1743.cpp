/*
 * @Author: sanjusss
 * @Date: 2021-07-26 08:32:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-26 08:45:11
 * @FilePath: \1000\1700\1740\1743.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> near;
        for (auto& p : adjacentPairs) {
            near[p[0]].push_back(p[1]);
            near[p[1]].push_back(p[0]);
        }

        int prev = INT_MIN;
        for (auto& [i, vec] : near) {
            if (vec.size() == 1) {
                prev = i;
                break;
            }
        }

        int cur = near[prev][0];
        vector<int> ans({ prev, cur });
        while (true) {
            auto& vec = near[cur];
            if (vec.size() == 1) {
                break;
            }
            else if (vec[0] == prev) {
                prev = cur;
                cur = vec[1];
                ans.push_back(cur);
            }
            else {
                prev = cur;
                cur = vec[0];
                ans.push_back(cur);
            }
        }

        return ans;
    }
};