/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-06 10:31:30
 * @FilePath: \C\C300\C350\C357\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string finalString(string s) {
        string ans;
        for (char i : s) {
            if (i == 'i') {
                reverse(ans.begin(), ans.end());
            }
            else {
                ans.push_back(i);
            }
        }

        return ans;
    }
};