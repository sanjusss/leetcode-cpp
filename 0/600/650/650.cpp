/*
 * @Author: sanjusss
 * @Date: 2021-09-20 08:33:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-20 09:12:45
 * @FilePath: \0\600\650\650.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minSteps(int n) {
//         vector<int> prime;
//         int maxF = sqrt(n);
//         for (int i = 2; i <= maxF; ++i) {
//             bool success = true;
//             for (int j : prime) {
//                 if (i % j == 0) {
//                     success = false;
//                     break;
//                 }
//             }

//             if (success) {
//                 prime.push_back(i);
//             }
//         }

//         int ans = 0;
//         for (int i : prime) {
//             while (n > 1 && n % i == 0) {
//                 ans += i;
//                 n /= i;
//             }
//         }

//         if (n > 1) {
//             ans += n;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i * i <= n && n > 1; ++i) {
            while (n > 1 && n % i == 0) {
                n /= i;
                ans += i;
            }
        }

        if (n > 1) {
            ans += n;
        }

        return ans;
    }
};

TEST(&Solution::minSteps)