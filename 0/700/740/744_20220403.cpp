/*
 * @Author: sanjusss
 * @Date: 2022-04-03 10:10:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-03 10:12:11
 * @FilePath: \0\700\740\744_20220403.cpp
 */
#include "leetcode.h"

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target == 'z') {
            return letters.front();
        }
        else {
            ++target;
        }

        auto p = lower_bound(letters.begin(), letters.end(), target);
        if (p == letters.end()) {
            return letters.front();
        }

        return *p;
    }
};