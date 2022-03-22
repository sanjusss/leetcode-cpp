/*
 * @Author: sanjusss
 * @Date: 2022-03-22 09:31:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-22 09:35:44
 * @FilePath: \2000\2000\2030\2038.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int a = 0;
        int b = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (colors[i] == 'A')
            {
                if (colors[i - 1] == 'A' && colors[i + 1] == 'A') {
                    ++a;
                }
            }
            else if (colors[i] == 'B')
            {
                if (colors[i - 1] == 'B' && colors[i + 1] == 'B') {
                    ++b;
                }
            }
        }

        return a > b;
    }
};