/*
 * @Author: sanjusss
 * @Date: 2022-05-12 09:02:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-12 09:07:49
 * @FilePath: \0\900\940\944.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            bool del = false;
            for (int j = 1; j < m; ++j) {
                if (strs[j - 1][i] > strs[j][i]) {
                    del = true;
                    break;
                }
            }

            if (del) {
                ++ans;
            }
        }

        return ans;
    }
};