/*
 * @Author: sanjusss
 * @Date: 2022-12-25 12:22:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-25 12:46:29
 * @FilePath: \1000\1700\1730\1739.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumBoxes(int n) {
        int sum = 1;
        int level = 1;
        int buttom = 1;
        while (sum < n) {
            buttom += ++level;
            sum += buttom;
        }

        while (sum >= n) {
            --buttom;
            sum -= level--;
        }

        return buttom + 1;
    }
};