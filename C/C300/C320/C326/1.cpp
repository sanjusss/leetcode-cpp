/*
 * @Author: sanjusss
 * @Date: 2023-01-01 10:21:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-01 10:33:17
 * @FilePath: \C\C300\C320\C326\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int n = num;
        while (n > 0) {
            if (num % (n % 10) == 0) {
                ++ans;
            }

            n /= 10;
        }

        return ans;
    }
};