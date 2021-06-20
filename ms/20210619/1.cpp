/*
 * @Author: sanjusss
 * @Date: 2021-06-19 15:00:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-19 15:03:03
 * @FilePath: \ms\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int leastMinutes(int n) {
        int s = 1;
        for (int i = 1; ; ++i) {
            if (s >= n) {
                return i;
            }
            else {
                s += s;
            }
        }

        return 0;
    }
};