/*
 * @Author: sanjusss
 * @Date: 2022-03-13 09:13:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-13 09:22:55
 * @FilePath: \0\300\390\393.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int r = 0;
        for (int i : data) {
            if (r == 0) {
                int cnt = 0;
                for (int j = 7; j >= 0; --j) {
                    if (i & (1 << j)) {
                        ++cnt;
                    }
                    else {
                        break;
                    }
                }

                if (cnt > 4) {
                    return false;
                }
                else if (cnt > 1) {
                    r = cnt - 1;
                }
                else if (cnt == 1) {
                    return false;
                }
            }
            else {
                if ((i & 0x80) == 0x80) {
                    --r;
                }
                else {
                    return false;
                }
            }
        }

        return r == 0;
    }
};