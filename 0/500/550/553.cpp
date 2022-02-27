/*
 * @Author: sanjusss
 * @Date: 2022-02-27 22:05:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-27 22:13:10
 * @FilePath: \0\500\550\553.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return to_string(nums[0]);
        }
        else if (n == 2) {
            return to_string(nums[0]) + '/' + to_string(nums[1]);
        }

        string ans = to_string(nums[0]) + "/("s;
        for (int i = 1; i < n; ++i) {
            if (i != 1) {
                ans += '/';
            }

            ans += to_string(nums[i]);
        }

        ans += ')';
        return ans;
    }
};