/*
 * @Author: sanjusss
 * @Date: 2023-05-11 09:06:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-11 09:18:19
 * @FilePath: \1000\1000\1010\1016.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> all;
        for (int w = min<int>(s.size(), 30); w > 0; --w) {
            int cur = 0;
            int mask = (1 << w) - 1;
            for (char c : s) {
                cur <<= 1;
                cur |= c - '0';
                cur &= mask;
                all.insert(cur);
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (!all.count(i)) {
                return false;
            }
        }

        return true;
    }
};