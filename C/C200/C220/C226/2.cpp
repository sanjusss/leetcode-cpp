/*
 * @Author: sanjusss
 * @Date: 2021-01-31 10:40:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-31 10:56:48
 * @FilePath: \C\C200\C220\C226\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> conn;
        for (auto& p : adjacentPairs) {
            conn[p[0]].push_back(p[1]);
            conn[p[1]].push_back(p[0]);
        }

        int prev = 0;
        int cur = 0;
        for (auto& [i, arr] : conn) {
            if (arr.size() == 1) {
                cur = arr[0];
                prev = i;
                break;
            }
        }

        vector<int> ans;
        ans.push_back(prev);
        while (true) {
            ans.push_back(cur);
            auto& arr = conn[cur];
            if (arr.size() == 1) {
                break;
            }
            else if (arr[0] == prev) {
                prev = cur;
                cur = arr[1];
            }
            else {
                prev = cur;
                cur = arr[0];
            }
        }

        return ans;
    }
};