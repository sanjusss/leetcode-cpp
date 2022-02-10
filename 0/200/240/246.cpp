/*
 * @Author: sanjusss
 * @Date: 2022-02-10 15:55:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-10 15:59:33
 * @FilePath: \0\200\240\246.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            if (num[i] == '1') {
                if (num[j] != '1') {
                    return false;
                }
            }
            else if (num[i] == '6') {
                if (num[j] != '9') {
                    return false;
                }
            }
            else if (num[i] == '9') {
                if (num[j] != '6') {
                    return false;
                }
            }
            else if (num[i] == '8') {
                if (num[j] != '8') {
                    return false;
                }
            }
            else if (num[i] == '0') {
                if (num[j] != '0') {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        return true;
    }
};