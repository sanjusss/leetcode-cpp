/*
 * @Author: sanjusss
 * @Date: 2022-10-04 08:06:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-04 08:09:46
 * @FilePath: \0\900\920\921.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int left = 0;
        for (char i : s) {
            if (i == '(') {
                ++left;
            }
            else if (left == 0) {
                ++ans;
            }
            else {
                --left;
            }
        }

        return ans + left;
    }
};