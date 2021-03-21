/*
 * @Author: sanjusss
 * @Date: 2021-03-21 10:57:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-21 11:27:40
 * @FilePath: \C\C200\C230\C234\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int64_t left = 1;
        int64_t right = maxSum + 1;
        int64_t mid;
        int64_t minTempSum;
        int lsize = index + 1;
        int rsize = n - index;
        while (left < right) {
            mid = (left + right) / 2;
            minTempSum = -mid;
            if (mid >= lsize) {
                minTempSum += (mid + mid - lsize + 1) * lsize / 2;
            }
            else {
                minTempSum += lsize - mid;
                minTempSum += (mid + 1) * mid / 2;
            }

            if (mid >= rsize) {
                minTempSum += (mid + mid - rsize + 1) * rsize / 2;
            }
            else {
                minTempSum += rsize - mid;
                minTempSum += (mid + 1) * mid / 2;
            }

            if (minTempSum <= maxSum) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left - 1;
    }
};

TEST(&Solution::maxValue)