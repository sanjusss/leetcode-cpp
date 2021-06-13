/*
 * @Author: sanjusss
 * @Date: 2021-06-13 09:57:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-13 09:59:42
 * @FilePath: \0\200\270\278_20210613.cpp
 */
#include "leetcode.h"

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (isBadVersion(mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};