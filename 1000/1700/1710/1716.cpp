/*
 * @Author: sanjusss
 * @Date: 2022-01-15 16:21:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-15 16:46:37
 * @FilePath: \1000\1700\1710\1716.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int totalMoney(int n) {
        int w = n / 7;
        int ans = (w - 1) * w / 2 * 7;
        ans += w * (1 + 7) * 7 / 2;
        ans += (1 + (n % 7) + w * 2) * (n % 7) / 2;
        return ans;
    }
};