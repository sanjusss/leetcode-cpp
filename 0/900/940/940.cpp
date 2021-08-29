/*
 * @Author: sanjusss
 * @Date: 2021-08-29 12:46:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-29 13:18:12
 * @FilePath: \0\900\940\940.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int distinctSubseqII(string s) {
        static constexpr int mod = 1e9 + 7;
        int last = 1;
        int ans = 1;
        array<int, 26> prev = { 0 };
        for (char c : s) {
            int i = c - 'a';
            ans = (ans * 2) % mod;
            ans = (ans - prev[i] + mod) % mod;
            prev[i] = last;
            last = ans;
        }

        ans = (ans - 1 + mod) % mod;
        return ans;
    }
};

TEST(&Solution::distinctSubseqII)