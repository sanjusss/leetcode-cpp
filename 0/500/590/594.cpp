/*
 * @Author: sanjusss
 * @Date: 2021-11-20 13:21:56
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-20 13:25:03
 * @FilePath: \0\500\590\594.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i : nums) {
            ++cnt[i];
        }

        int ans = 0;
        for (auto [i, c] : cnt) {
            if (cnt.count(i + 1)) {
                ans = max(ans, c + cnt[i + 1]);
            }
        }

        return ans;
    }
};