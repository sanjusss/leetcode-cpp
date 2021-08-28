/*
 * @Author: sanjusss
 * @Date: 2021-08-28 09:43:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-28 09:43:54
 * @FilePath: \1000\1400\1480\1480.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        for (int i : nums) {
            sum += i;
            ans.push_back(sum);
        }

        return ans;
    }
};