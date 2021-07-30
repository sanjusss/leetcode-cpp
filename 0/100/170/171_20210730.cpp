/*
 * @Author: sanjusss
 * @Date: 2021-07-30 08:20:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-30 08:25:18
 * @FilePath: \0\100\170\171_20210730.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (char i : columnTitle) {
            ans = ans * 26 + (i - 'A' + 1);
        }

        return ans;
    }
};

TEST(&Solution::titleToNumber)