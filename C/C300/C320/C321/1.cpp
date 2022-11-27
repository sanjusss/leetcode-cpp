/*
 * @Author: sanjusss
 * @Date: 2022-11-27 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-27 10:33:39
 * @FilePath: \C\C300\C320\C321\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int pivotInteger(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            int lsum = (1 + mid) * mid / 2;
            int rsum = (mid + n) * (n - mid + 1) / 2;
            if (lsum == rsum) {
                return mid;
            }
            else if (lsum > rsum) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;
    }
};