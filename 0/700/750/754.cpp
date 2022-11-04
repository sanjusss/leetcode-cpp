/*
 * @Author: sanjusss
 * @Date: 2022-11-04 08:49:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-04 09:14:35
 * @FilePath: \0\700\750\754.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int reachNumber(int target) {
//         int ans = 0;
//         target = abs(target);
//         int sum = 0;
//         while (sum < target) {
//             sum += ++ans;
//         }

//         if ((sum - target) % 2 == 0) {
//             return ans;
//         }
//         else if (ans % 2 == 0) {
//             return ans + 1;
//         }
//         else {
//             return ans + 2;
//         }
//     }
// };


class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int ans = ceil((-1 + sqrt(1 + 8ll * target)) / 2);
        int sum = ans * (ans + 1) / 2;
        if ((sum - target) % 2 == 0) {
            return ans;
        }
        else {
            return ans + 1 + ans % 2;
        }
    }
};
