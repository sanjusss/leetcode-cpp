/*
 * @Author: sanjusss
 * @Date: 2023-02-28 12:54:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-28 12:56:02
 * @FilePath: \2000\2300\2360\2363.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> cnt;
        for (auto& i : items1) {
            cnt[i[0]] += i[1];
        }

        for (auto& i : items2) {
            cnt[i[0]] += i[1];
        }

        vector<vector<int>> ans;
        for (auto [k, v] : cnt) {
            ans.push_back({{ k, v }});
        }

        return ans;
    }
};