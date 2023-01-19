/*
 * @Author: sanjusss
 * @Date: 2023-01-19 08:55:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-19 09:00:37
 * @FilePath: \2000\2200\2290\2299.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) {
            return false;
        }

        bool hasLow = false;
        bool hasUpper = false;
        bool hasNumber = false;
        bool hasSpeical = false;
        char prev = 0;
        for (char i : password) {
            if (i == prev) {
                return false;
            }
            else {
                prev = i;
            }

            if (i >= 'a' && i <= 'z') {
                hasLow = true;
            }
            else if (i >= 'A' && i <= 'Z') {
                hasUpper = true;
            }
            else if (i >= '0' && i <= '9') {
                hasNumber = true;
            }
            else {
                hasSpeical = true;
            }
        }

        return hasLow && hasUpper && hasNumber && hasSpeical;
    }
};