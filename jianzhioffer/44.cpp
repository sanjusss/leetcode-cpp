/*
 * @Author: sanjusss
 * @Date: 2021-09-05 10:10:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-05 15:02:49
 * @FilePath: \jianzhioffer\44.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findNthDigit(int n) {
//         int left = 1;
//         int right = INT_MAX;
//         while (left < right) {
//             int mid = left + (right - left) / 2;
//             int64_t count = digitCount(mid);
//             if (count >= n) {
//                 right = mid;
//             }
//             else {
//                 left = mid + 1;
//             }
//         }

//         int64_t count = digitCount(left);
//         while (count > n) {
//             left /= 10;
//             --count;
//         }

//         return left % 10;
//     }

// private:
//     int64_t digitCount(int i) {
//         int64_t ans = 0;
//         int64_t len = 0;
//         int prev = 0;
//         int64_t b = 1;
//         while (i  > 0) {
//             b *= 10;
//             ++len;
//             int cur = b - 1 - prev;
//             if (i >= cur) {
//                 prev += cur;
//                 i -= cur;
//                 ans += len * cur;
//             }
//             else {
//                 ans += len * i;
//                 i = 0;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int findNthDigit(int n) {
        int64_t next = 9;
        int len = 1;
        int64_t start = 1;
        while (next < n) {
            n -= next;
            ++len;
            start *= 10;
            next = start * len * 9;
        }

        int number = start + (n - 1) / len;
        int target = (n - 1) % len + 1;
        while (target < len) {
            number /= 10;
            --len;
        } 

        return number % 10;
    }
};

TEST(&Solution::findNthDigit)