/*
 * @Author: sanjusss
 * @Date: 2021-08-15 10:33:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-15 10:40:22
 * @FilePath: \C\C200\C250\C254\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        ans.reserve(n);
        int smaller = 0;
        int bigger = n / 2;
        bool useBigger = true;
        while (ans.size() < n) {
            if (useBigger) {
                ans.push_back(nums[bigger++]);
            }
            else {
                ans.push_back(nums[smaller++]);
            }

            useBigger = !useBigger;
        }

        return ans;
    }
};