/*
 * @Author: sanjusss
 * @Date: 2021-10-07 15:02:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-07 15:03:49
 * @FilePath: \0\400\480\434.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        bool hasWord = false;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                if (hasWord) {
                    ++ans;
                    hasWord = false;
                }
            }
            else {
                hasWord = true;
            }
        }

        return ans;
    }
};