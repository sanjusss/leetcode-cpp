/*
 * @Author: sanjusss
 * @Date: 2022-08-05 08:37:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-05 08:49:14
 * @FilePath: \0\400\400\408.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int cnt = 0;
        int wn = word.size();
        int an = abbr.size();
        int wi = 0;
        int ai = 0;
        while (wi < wn && ai < an) {
            if (abbr[ai] >= 'a' && abbr[ai] <= 'z') {
                wi += cnt;
                if (wi >= wn || word[wi] != abbr[ai]) {
                    return false;
                }
                else {
                    ++wi;
                    ++ai;
                    cnt = 0;
                }
            }
            else {
                int v = abbr[ai++] - '0';
                if (cnt == 0 && v == 0) {
                    return false;
                }

                cnt = cnt * 10 + v;
            }
        }

        return wi + cnt == wn && ai == an;
    }
};