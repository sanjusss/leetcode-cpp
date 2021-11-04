/*
 * @Author: sanjusss
 * @Date: 2021-11-04 08:21:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-04 08:25:30
 * @FilePath: \0\300\360\367_20211104.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (num % mid == 0 && num / mid == mid) {
                return true;
            }
            else if (num / mid >= mid) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};