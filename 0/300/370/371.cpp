/*
 * @Author: sanjusss
 * @Date: 2021-09-26 08:26:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-26 08:46:22
 * @FilePath: \0\200\270\271.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int getSum(int a, int b) {
        uint32_t ans = a;
        uint32_t r = b;
        while (r) {
            uint32_t next = (ans & r) << 1;
            ans ^= r;
            r = next;
        }

        return ans;
    }
};

TEST(&Solution::getSum)