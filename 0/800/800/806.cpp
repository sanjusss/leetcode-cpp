/*
 * @Author: sanjusss
 * @Date: 2022-04-12 08:36:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-12 08:39:59
 * @FilePath: \0\800\800\806.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1;
        int len = 0;
        for (char c : s) {
            int w = widths[c - 'a'];
            if (len + w > 100) {
                len = w;
                ++line;
            }
            else {
                len += w;
            }
        }

        return { { line, len } };
    }
};