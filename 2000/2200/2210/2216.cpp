/*
 * @Author: sanjusss
 * @Date: 2023-11-21 08:32:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-21 09:08:12
 * @FilePath: \2000\2200\2210\2216.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if ((i - cnt) % 2 == 0 && i + 1 < n && nums[i] == nums[i + 1]) {
                ++cnt;
            }
        }

        if ((n - cnt) % 2 != 0) {
            ++cnt;
        }

        return cnt;
    }
};