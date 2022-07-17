/*
 * @Author: sanjusss
 * @Date: 2022-07-17 10:28:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-17 10:36:50
 * @FilePath: \C\C300\C300\C302\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> all;
        for (int i : nums) {
            int sum = 0;
            int j = i;
            while (j != 0) {
                sum += j % 10;
                j /= 10;
            }

            auto& [f, s] = all[sum];
            if (i > f) {
                s = f;
                f = i;
            }
            else if (i > s) {
                s = i;
            }
        }

        int ans = -1;
        for (auto& [_, p] : all) {
            if (p.first > 0 && p.second > 0) {
                ans = max(ans, p.first + p.second);
            }
        }

        return ans;
    }
};