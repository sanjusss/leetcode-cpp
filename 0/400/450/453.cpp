/*
 * @Author: sanjusss
 * @Date: 2021-10-20 08:28:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-20 08:29:24
 * @FilePath: \0\400\450\453.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int target = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for (int i : nums) {
            ans += i - target;
        }

        return ans;
    }
};