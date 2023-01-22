/*
 * @Author: sanjusss
 * @Date: 2023-01-22 10:39:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-22 11:03:12
 * @FilePath: \C\C300\C320\C329\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        // 00 -> 00
        // 01 -> 11
        // 10 -> 11
        // 11 -> 10
        int n = s.size();
        int one = 0;
        int zero = 0;
        int needOne = 0;
        int needZero = 0;
        bool modify = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] != target[i]) {
                modify = true;
            }

            if (s[i] == '1') {
                ++one;
            }
            else {
                ++zero;
            }
            
            if (target[i] == '0') {
                ++needZero;
            }
            else {
                ++needOne;
            }
        }

        if (!modify) {
            return true;
        }

        if (needZero > 0) {
            if (needOne == 0) {
                return false;
            }

            return one > 0;
        }
        else {
            return one > 0;
        }
    }
};