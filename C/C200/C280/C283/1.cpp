/*
 * @Author: sanjusss
 * @Date: 2022-03-06 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-06 10:33:04
 * @FilePath: \C\C200\C280\C283\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for (char i = s[0]; i <= s[3]; ++i) {
            for (char j = s[1]; j <= s[4]; ++j) {
                ans.push_back({ i, j });
            }
        }

        return ans;
    }
};