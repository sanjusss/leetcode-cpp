/*
 * @Author: sanjusss
 * @Date: 2023-03-23 09:12:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-23 09:34:20
 * @FilePath: \1000\1600\1630\1630.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; ++i) {
            int left = l[i];
            int right = r[i] + 1;
            int len = right - left;
            if (len <= 2) {
                ans[i] = true;
                continue;
            }

            vector<int> tmp(nums.begin() + left, nums.begin() + right);
            sort(tmp.begin(), tmp.end());
            bool res = true;
            for (int j = 2; j < len; ++j) {
                if (tmp[j - 1] - tmp[j - 2] != tmp[j] - tmp[j - 1]) {
                    res = false;
                    break;
                }
            }

            ans[i] = res;
        }

        return ans;
    }
};