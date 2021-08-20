/*
 * @Author: sanjusss
 * @Date: 2021-08-20 08:18:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-20 08:24:46
 * @FilePath: \0\500\540\541.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            reverse(s.begin() + i, s.begin() + min(n, i + k));
        }

        return s;
    }
};

TEST(&Solution::reverseStr)