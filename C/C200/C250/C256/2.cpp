/*
 * @Author: sanjusss
 * @Date: 2021-08-29 10:21:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-29 10:47:20
 * @FilePath: \C\C200\C250\C256\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), [](const string& a, const string& b) {
            if (a.size() != b.size()) {
                return a.size() > b.size();
            }
            else {
                return a > b;
            }
        });
        return nums[k - 1];
    }
};