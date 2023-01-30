/*
 * @Author: sanjusss
 * @Date: 2023-01-30 09:09:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-30 09:10:23
 * @FilePath: \2000\2300\2310\2315.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countAsterisks(string s) {
        bool in = false;
        int ans = 0;
        for (char i : s) {
            if (i == '|') {
                in = !in;
            }
            else if (i == '*' && !in) {
                ++ans;
            }
        }

        return ans;
    }
};