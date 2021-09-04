/*
 * @Author: sanjusss
 * @Date: 2021-09-04 15:26:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-04 15:30:08
 * @FilePath: \jianzhioffer\17.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> printNumbers(int n) {
        int end = 1;
        while (n > 0) {
            end *= 10;
            --n;
        }

        vector<int> ans(end - 1);
        iota(ans.begin(), ans.end(), 1);
        return ans;
    }
};