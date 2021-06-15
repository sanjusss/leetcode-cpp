/*
 * @Author: sanjusss
 * @Date: 2021-06-15 08:46:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-15 09:03:12
 * @FilePath: \0\0\80\89.cpp
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
                ans.push_back(prefix | ans[j]);
            }
        }

        return ans;
    }
};