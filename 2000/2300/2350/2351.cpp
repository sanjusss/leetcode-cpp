/*
 * @Author: sanjusss
 * @Date: 2023-01-01 10:15:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-01 10:15:44
 * @FilePath: \2000\2300\2350\2351.cpp
 */
#include "leetcode.h"

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> has(26);
        for (char c : s) {
            if (has[c - 'a']) {
                return c;
            }
            else {
                has[c - 'a'] = true;
            }
        }

        return 0;
    }
};