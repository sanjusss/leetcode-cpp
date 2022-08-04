/*
 * @Author: sanjusss
 * @Date: 2022-08-04 08:45:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-04 08:53:11
 * @FilePath: \1000\1400\1400\1403.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), greater<int>());
        int sub = 0;
        vector<int> ans;
        for (int i : nums) {
            sub += i;
            sum -= i;
            ans.push_back(i);
            if (sub > sum) {
                break;
            }
        }

        return ans;
    }
};