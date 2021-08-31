/*
 * @Author: sanjusss
 * @Date: 2021-08-31 08:54:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-31 09:03:34
 * @FilePath: \jianzhioffer\67.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        int n = str.size();
        while (i < n && str[i] == ' ') {
            ++i;
        }

        int64_t ans = 0;
        int sign = 1;
        bool hasSign = false;
        while (i < n) {
            if (str[i] == '-') {
                if (hasSign) {
                    break;
                }
                else {
                    sign = -1;
                    hasSign = true;
                }
            }
            else if (str[i] == '+') {
                if (hasSign) {
                    break;
                }
                else {
                    hasSign = true;
                }
            }
            else if (isdigit(str[i])) {
                hasSign = true;
                ans = ans * 10 + str[i] - '0';
                if (ans > INT_MAX) {
                    if (sign == 1) {
                        return INT_MAX;
                    }
                    else {
                        return INT_MIN;
                    }
                }
            }
            else {
                break;
            }

            ++i;
        }

        return ans * sign;
    }
};