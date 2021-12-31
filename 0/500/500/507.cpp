/*
 * @Author: sanjusss
 * @Date: 2021-12-31 09:07:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-31 09:25:20
 * @FilePath: \0\500\500\507.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }

        int imax = min((int)sqrt(num), num - 1);
        int sum = 1;
        for (int i = 2; i <= imax; ++i) {
            if (num % i == 0) {
                sum += i;
                if (num / i != i) {
                    sum += num / i;
                }
            }
        }

        return sum == num;
    }
};

TEST(&Solution::checkPerfectNumber)