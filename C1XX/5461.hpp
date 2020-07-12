#pragma once
#include "leetcode.h"

class Solution {
public:
    int numSub(string s) {
        int64_t ans = 0;
        int64_t ones = 0;
        for (char i : s) {
            if (i == '1') {
                ++ones;
            }
            else if (ones > 0) {
                ans += ones * (ones + 1) / 2;
                ones = 0;
            }
        }

        if (ones > 0) {
            ans += ones * (ones + 1) / 2;
            ones = 0;
        }

        return ans % int64_t(1e9 + 7);
    }
};