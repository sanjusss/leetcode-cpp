/*
 * @Author: sanjusss
 * @Date: 2021-09-22 07:37:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-22 07:39:08
 * @FilePath: \0\0\50\58.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (ans > 0) {
                    break;
                }
            }
            else {
                ++ans;
            }
        }

        return ans;
    }
};