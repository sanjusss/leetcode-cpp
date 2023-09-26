/*
 * @Author: sanjusss
 * @Date: 2023-09-26 08:55:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-26 09:00:40
 * @FilePath: \2000\2500\2580\2582.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int passThePillow(int n, int time) {
        int r = time / (n - 1);
        int i = time % (n - 1);
        if (r % 2 == 0) {
            return 1 + i;
        }
        else {
            return n - i;
        }
    }
};