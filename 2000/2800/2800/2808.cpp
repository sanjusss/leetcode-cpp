/*
 * @Author: sanjusss
 * @Date: 2024-01-30 09:35:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-01-30 10:34:07
 * @FilePath: \2000\2800\2800\2808.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }

        int ans = n / 2;
        for (auto &[_, ps] : pos) {
            int m = ps.size();
            if (m == 1) {
                continue;
            }

            int len = 1;
            for (int j = 0; j < m; ++j) {
                int a = ps[j];
                int b = ps[(j + m - 1) % m];
                len = max(len, ((a + n - b) % n ));
            }

            ans = min(ans, len / 2);
        }

        return ans;
    }
};

TEST(&Solution::minimumSeconds)