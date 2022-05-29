/*
 * @Author: sanjusss
 * @Date: 2022-05-28 08:25:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-28 08:27:31
 * @FilePath: \1000\1000\1020\1021.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans;
        for (char i : s) {
            if (i == '(') {
                if (cnt++ > 0) {
                    ans.push_back(i);
                }
            }
            else {
                if (--cnt > 0) {
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
}; 