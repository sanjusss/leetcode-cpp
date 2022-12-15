/*
 * @Author: sanjusss
 * @Date: 2022-12-15 08:42:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-15 08:56:16
 * @FilePath: \1000\1900\1940\1945.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for (char i : s) {
            int v = i - 'a' + 1;
            ans += v / 10 + v % 10;
        }

        for (int i = 2; i <= k; ++i) {
            int v = ans;
            ans = 0;
            while (v > 0) {
                ans += v % 10;
                v /= 10;
            }
        }

        return ans;
    }
};