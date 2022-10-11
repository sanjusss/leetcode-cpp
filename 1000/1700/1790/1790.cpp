/*
 * @Author: sanjusss
 * @Date: 2022-10-11 08:15:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-11 08:22:19
 * @FilePath: \1000\1700\1790\1790.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int p1 = -1;
        int p2 = -1;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }
            else if (p1 == -1) {
                p1 = i;
            }
            else if (p2 == -1) {
                p2 = i;
            }
            else {
                return false;
            }
        }

        if (p1 == -1) {
            return true;
        }
        else if (p2 == -1) {
            return false;
        }
        else {
            return s1[p1] == s2[p2] && s1[p2] == s2[p1];
        }
    }
};