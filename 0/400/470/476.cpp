/*
 * @Author: sanjusss
 * @Date: 2021-10-18 08:40:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-18 08:45:15
 * @FilePath: \0\400\470\476.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int bit = 1;
        while (num > 0) {
            if (!(num & 1)) {
                ans += bit;
            }

            num >>= 1;
            bit <<= 1;
        }

        return ans;
    }
};