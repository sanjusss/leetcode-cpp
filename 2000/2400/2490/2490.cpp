/*
 * @Author: sanjusss
 * @Date: 2023-06-30 08:27:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-30 08:29:42
 * @FilePath: \2000\2400\2490\2490.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        for (int i = 0; i < n; ++i) {
            if (sentence[i] != ' ') {
                continue;
            }

            if (i == 0 || i + 1 == n || sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }

        return sentence.back() == sentence.front();
    }
};