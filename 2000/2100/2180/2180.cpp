/*
 * @Author: sanjusss
 * @Date: 2023-01-06 08:34:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-06 09:34:39
 * @FilePath: \2000\2100\2180\2180.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int countEven(int num) {
//         int ans = 0;
//         for (int i = 1; i <= num; ++i) {
//             int j = i;
//             int sum = 0;
//             while (j > 0) {
//                 sum += j % 10;
//                 j /= 10;
//             }

//             if (sum % 2 == 0) {
//                 ++ans;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int countEven(int num) {
        int pre = num / 10;
        int suf = num % 10;
        int ans = pre * 5;
        int preSum = 0;
        while (pre > 0) {
            preSum += pre % 10;
            pre /= 10;
        }

        if (preSum & 1) {
            ans += (suf + 1) / 2;
        }
        else {
            ans += suf / 2 + 1;
        }

        return ans - 1;
    }
};