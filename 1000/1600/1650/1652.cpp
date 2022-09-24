/*
 * @Author: sanjusss
 * @Date: 2022-09-24 08:41:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-24 09:03:42
 * @FilePath: \1000\1600\1650\1652.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if (k == 0) {
            return ans;
        }

        vector<int> sum;
        int cur = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j : code) {
                cur += j;
                sum.push_back(cur);
            }
        }

        if (k > 0) {
            for (int i = 0; i < n; ++i) {
                ans[i] = sum[i + k] - sum[i];
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                ans[i] = sum[i + n - 1] - sum[i + n - 1 + k];
            }
        }

        return ans;
    }
};