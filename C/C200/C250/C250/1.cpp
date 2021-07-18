/*
 * @Author: sanjusss
 * @Date: 2021-07-18 10:30:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-18 10:35:28
 * @FilePath: \C\C200\C250\C250\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(CHAR_MAX + 1);
        for (char i : brokenLetters) {
            broken[i] = true;
        }

        int ans = 0;
        bool success = true;
        for (char i : text) {
            if (i == ' ') {
                if (success) {
                    ++ans;
                }

                success = true;
            }
            else if (broken[i]) {
                success = false;
            }
        }

        if (success) {
            ++ans;
        }

        return ans;
    }
};