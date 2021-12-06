/*
 * @Author: sanjusss
 * @Date: 2021-12-06 15:39:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-06 15:41:01
 * @FilePath: \1000\1800\1810\1816.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        for (char i : s) {
            if (i == ' ' && --k <= 0) {
                break;
            }

            ans.push_back(i);
        }

        return ans;
    }
};