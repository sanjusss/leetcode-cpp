/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-20 10:31:13
 * @FilePath: \C\C300\C350\C359\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<pair<int, int>> rs;
        for (auto& i : nums) {
            int b = i[0];
            int e = i[1];
            if (rs.empty() || rs.back().second < b) {
                rs.emplace_back(b, e);
            }
            else {
                rs.back().second = max(rs.back().second, e);
            }
        }

        int ans = 0;
        for (auto [b, e] : rs) {
            ans += e - b + 1;
        }

        return ans;
    }
};