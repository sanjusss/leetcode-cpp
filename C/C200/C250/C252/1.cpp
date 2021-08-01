/*
 * @Author: sanjusss
 * @Date: 2021-08-01 10:28:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-01 10:32:17
 * @FilePath: \C\C200\C250\C252\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for (int i = 1; i < n && cnt <= 2; ++i) {
            if (n % i == 0) {
                ++cnt;
            }
        }

        return cnt == 2;
    }
};