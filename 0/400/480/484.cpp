/*
 * @Author: sanjusss
 * @Date: 2022-08-16 08:27:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-16 08:41:36
 * @FilePath: \0\400\480\484.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size();
        vector<int> ans(n + 1);
        int minV = 0;
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == 'I') {
                ans[i] = ++minV;
                for (int j = i - 1; j >= 0 && s[j] =='D'; --j) {
                    ans[j] = ++minV;
                }
            }
        }
        return ans;
    }
};