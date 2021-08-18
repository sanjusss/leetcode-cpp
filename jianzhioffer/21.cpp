/*
 * @Author: sanjusss
 * @Date: 2021-08-18 09:08:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-18 09:12:47
 * @FilePath: \jianzhioffer\21.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0;
        int right = n - 1;
        for (int i : nums) {
            if (i & 1) {
                ans[left++] = i;
            }
            else {
                ans[right--] = i;
            }
        }

        return ans;
    }
};