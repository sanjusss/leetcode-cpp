/*
 * @Author: sanjusss
 * @Date: 2022-09-25 09:58:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-25 10:01:07
 * @FilePath: \0\700\780\788.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (isGood(i)) {
                ++ans;
            }
        }

        return ans;
    }

private:
    bool isGood(int n) {
        bool hasDiff = false;
        while (n > 0) {
            switch (n % 10) {
                case 0:
                case 1:
                case 8:
                    break;

                case 2:
                case 5:
                case 6:
                case 9:
                    hasDiff = true;
                    break;

                default:
                    return false;
            }

            n /= 10;
        }

        return hasDiff;
    }
};