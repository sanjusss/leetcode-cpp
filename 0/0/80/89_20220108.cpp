/*
 * @Author: sanjusss
 * @Date: 2022-01-08 10:05:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-08 10:21:25
 * @FilePath: \0\0\80\89_20220108.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.reserve(1 << n);
        ans.push_back(0);
        for (int i = 0; i < n; ++i) {
            int prefix = 1 << i;
            for (int j = ans.size() - 1; j >= 0; --j) {
                ans.push_back(ans[j] + prefix);
            }
        }

        return ans;
    }
};