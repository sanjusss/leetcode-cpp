/*
 * @Author: sanjusss
 * @Date: 2022-05-18 08:51:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-18 09:18:23
 * @FilePath: \0\600\660\668.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findKthNumber(int m, int n, int k) {
//         if (m > n) {
//             return findKthNumber(n, m, k);
//         }

//         int left = 1;
//         int right = m * n;
//         while (left < right) {
//             int mid = (left + right + 1) / 2;
//             int begin = 1;
//             int end = 0;
//             for (int i = 1; i <= m; ++i) {
//                 begin += min((mid - 1) / i, n);
//                 end += min(mid / i, n);
//             }

//             if (end < k) {
//                 left = mid + 1;
//             }
//             else if (begin > k) {
//                 right = mid - 1;
//             }
//             else {
//                 return mid;
//             }
//         }

//         return left;
//     }
// };

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        if (m > n) {
            return findKthNumber(n, m, k);
        }

        int left = 1;
        int right = m * n;
        while (left < right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int i = 1; i <= m; ++i) {
                cnt += min(mid / i, n);
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

TEST(&Solution::findKthNumber)