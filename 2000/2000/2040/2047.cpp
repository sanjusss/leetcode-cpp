/*
 * @Author: sanjusss
 * @Date: 2022-01-27 10:47:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-27 11:11:23
 * @FilePath: \2000\2000\2040\2047.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countValidWords(string sentence) {
        int n = sentence.size();
        int ans = 0;
        bool valid = true;
        int len = 0;
        bool hyphen = false;
        bool punctuation = false;
        for (int i = 0; i <= n; ++i) {
            if (i == n || sentence[i] == ' ') {
                if (valid && len > 0) {
                    ++ans;
                }

                valid = true;
                len = 0;
                hyphen = false;
                punctuation = false;
                continue;
            }

            ++len;
            if (isdigit(sentence[i])) {
                valid = false;
            }
            else if (sentence[i] == '-') {
                if (hyphen || i == 0 || i == n - 1 || !isalpha(sentence[i - 1]) || !isalpha(sentence[i + 1])) {
                    valid = false;
                }

                hyphen = true;
            }
            else if (sentence[i] == '.' || sentence[i] == ',' || sentence[i] == '!') {
                if (punctuation) {
                    valid = false;
                }
                else {
                    punctuation = true;
                }
            }
            else if (punctuation) {
                valid = false;
            }
        }

        return ans;
    }
};