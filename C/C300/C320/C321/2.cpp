/*
 * @Author: sanjusss
 * @Date: 2022-11-27 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-27 10:38:37
 * @FilePath: \C\C300\C320\C321\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.size();
        int i = 0;
        for (char c : s) {
            if (c == t[i]) {
                if (++i == n) {
                    return 0;
                }
            }
        }

        return n - i;
    }
};