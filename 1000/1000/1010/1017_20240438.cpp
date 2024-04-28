/*
 * @Author: sanjusss
 * @Date: 2024-04-28 18:08:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-04-28 19:40:12
 * @FilePath: \1000\1000\1010\1017_20240438.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) {
            return "0"s;
        }

        string ans;
        while (n != 0) {
            int r = (abs(n) % 2);
            ans.push_back('0' + r);
            n -= r;
            n /= -2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

TEST(&Solution::baseNeg2)