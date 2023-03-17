/*
 * @Author: sanjusss
 * @Date: 2023-03-17 10:07:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-17 10:13:20
 * @FilePath: \2000\2300\2380\2389.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> sums;
        int sum = 0;
        for (int i : nums) {
            sum += i;
            sums.push_back(sum);
        }

        vector<int> ans;
        for (int q : queries) {
            auto p = upper_bound(sums.begin(), sums.end(), q);
            ans.push_back(p - sums.begin());
        }

        return ans;
    }
};