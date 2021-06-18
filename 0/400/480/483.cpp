/*
 * @Author: sanjusss
 * @Date: 2021-06-18 08:29:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-18 09:08:07
 * @FilePath: \0\400\480\483.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string smallestGoodBase(string n) {
        uint64_t i = stoull(n);
        int ones = 64;
        while (!((1ull << (ones - 1)) & i)) {
            --ones;
        }

        for (; ones > 0; --ones) {
            uint64_t left = 2;
            uint64_t right = i - 1;
            uint64_t mid;
            while (left <= right) {
                mid = left + (right - left) / 2;
                uint64_t val = 0;
                int j = 0;
                for (; j < ones && (i - 1) / mid >= val; ++j) {
                    val = val * mid + 1;
                }

                if (j < ones || val > i) {
                    right = mid - 1;
                }
                else if (val == i) {
                    return to_string(mid);
                }
                else {
                    left = mid + 1;
                }
            }
        }

        return ""s;
    }
};

TEST(&Solution::smallestGoodBase)