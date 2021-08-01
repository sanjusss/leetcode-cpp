/*
 * @Author: sanjusss
 * @Date: 2021-08-01 10:28:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-01 11:39:30
 * @FilePath: \C\C200\C250\C252\3.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     long long minimumPerimeter(long long neededApples) {
//         int64_t e = 0;
//         int64_t cur = 0;
//         while (cur < neededApples) {
//             ++e;
//             cur = (e + 1) * e / 2 * (e + e + 1) * 4;
//         } 

//         return e * 8;
//     }
// };

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        int64_t left = 0;
        int64_t right = 1e5 + 1;
        while (left < right) {
            int64_t mid = (left + right) / 2;
            if ((mid + 1) * mid * (mid + mid + 1) * 2 >= neededApples) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left * 8;
    }
};

TEST(&Solution::minimumPerimeter)