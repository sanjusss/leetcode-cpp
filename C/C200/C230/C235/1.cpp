/*
 * @Author: sanjusss
 * @Date: 2021-04-04 10:29:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-04 10:32:03
 * @FilePath: \C\C200\C230\C235\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        for (char c : s) {
            if (c == ' ' && --k == 0) {
                break;
            }
            else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};