#pragma once
#include "leetcode.h"

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int prevCount = 0;
        int curCount = 0;
        char cur = 0;
        for (char i : s) {
            if (i == cur) {
                ++curCount;
            }
            else {
                cur = i;
                ans += min(prevCount, curCount);
                prevCount = curCount;
                curCount = 1;
            }
        }

        if (curCount > 0) {
            ans += min(prevCount, curCount);
        }

        return ans;
    }
};