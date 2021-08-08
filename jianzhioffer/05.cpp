/*
 * @Author: sanjusss
 * @Date: 2021-08-08 08:54:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-08 08:55:28
 * @FilePath: \jianzhioffer\05.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for (char i : s) {
            if (i == ' ') {
                ans += "%20"s;
            }
            else {
                ans.push_back(i);
            }
        }

        return ans;
    }
};