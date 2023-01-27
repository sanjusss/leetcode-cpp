/*
 * @Author: sanjusss
 * @Date: 2023-01-27 09:37:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-27 09:39:43
 * @FilePath: \2000\2300\2300\2309.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> cs(s.begin(), s.end());
        for (int i = 25; i >= 0; --i) {
            if (cs.count('a' + i) && cs.count('A' + i)) {
                return { { static_cast<char>('A' + i) } };
            }
        }

        return {};
    }
};