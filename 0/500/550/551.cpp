/*
 * @Author: sanjusss
 * @Date: 2021-08-17 08:29:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-17 08:31:52
 * @FilePath: \0\500\550\551.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkRecord(string s) {
        bool hasA = false;
        int LCnt = 0;
        for (char i : s) {
            if (i == 'L') {
                if (++LCnt == 3) {
                    return false;
                }

                continue;
            }

            LCnt = 0;
            if (i == 'A') {
                if (hasA) {
                    return false;
                }
                else {
                    hasA = true;
                }
            }
        }

        return true;
    }
};

TEST(&Solution::checkRecord)