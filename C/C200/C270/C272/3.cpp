/*
 * @Author: sanjusss
 * @Date: 2021-12-19 10:14:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-19 10:42:28
 * @FilePath: \C\C200\C270\C272\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long cnt = 0;
        int prev = INT_MIN;
        for (int i : prices) {
            if (i + 1 == prev) {
                ++cnt;
            }
            else {
                cnt = 1;
            }

            prev = i;
            ans += cnt;
        }

        return ans;
    }
};