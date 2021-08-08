/*
 * @Author: sanjusss
 * @Date: 2021-08-08 10:29:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-08 10:41:53
 * @FilePath: \C\C200\C250\C253\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minSwaps(string s) {
        int left = 0;
        for (char i : s) {
            if (i == '[') {
                ++left;
            }
            else if (left > 0) {
                --left;
            }
        }

        return (left + 1) / 2;
    }
};