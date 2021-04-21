/*
 * @Author: sanjusss
 * @Date: 2021-04-21 22:22:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-21 22:36:59
 * @FilePath: \0\0\90\91.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numDecodings(string s) {
        int prev2 = 1;
        int prev1 = s[0] == '0' ? 0 : 1;
        for (int i = 1; i < s.size(); ++i) {
            int cur = 0;
            if (s[i] != '0') {
                cur += prev1;
            }

            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                cur += prev2;
            }

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};

TEST(&Solution::numDecodings)