/*
 * @Author: sanjusss
 * @Date: 2021-12-05 21:39:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-05 21:53:15
 * @FilePath: \0\300\370\372.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        static constexpr int mod = 1337;
        a %= mod;
        int ans = 1;
        int fac = a;
        for (int i = b.size() - 1; i >= 0; --i) {
            for (int j = 0; j < b[i]; ++j) {
                ans *= fac;
                ans %= mod;
            }

            int next = 1;
            for (int j = 0; j < 10; ++j) {
                next *= fac;
                next %= mod;
            }

            fac = next;
        }

        return ans;
    }
};