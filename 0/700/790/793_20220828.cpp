/*
 * @Author: sanjusss
 * @Date: 2022-08-28 09:39:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-28 09:48:38
 * @FilePath: \0\700\790\793_20220828.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int preimageSizeFZF(int k) {
        return findMinX(k + 1) - findMinX(k);
    }

private:
    static int findMinX(int k) {
        int64_t left = 0;
        int64_t right = k * (int64_t)5;
        while (left < right) {
            int64_t mid = (right - left) / 2 + left;
            int64_t cnt = 0;
            int64_t cur = mid;
            while (cur > 0) {
                cur /= 5;
                cnt += cur;
            }

            if (cnt >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};