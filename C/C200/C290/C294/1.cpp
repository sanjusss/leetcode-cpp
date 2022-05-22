/*
 * @Author: sanjusss
 * @Date: 2022-05-22 10:29:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-22 10:31:45
 * @FilePath: \C\C200\C290\C294\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for (char i : s) {
            if (i == letter) {
                ++cnt;
            }
        }

        return cnt * 100 / s.size();
    }
};