/*
 * @Author: sanjusss
 * @Date: 2021-07-22 09:04:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-22 09:16:00
 * @FilePath: \1000\1900\1920\1925.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int countTriples(int n) {
//         int ans = 0;
//         for (int i = 1; i <= n; ++i) {
//             for (int j = i + 1; j <= n; ++j) {
//                 for (int k = j + 1; k <= n; ++k) {
//                     if (i * i + j * j == k * k) {
//                         ans += 2;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int countTriples(int n) {
//         unordered_set<int> vs;
//         int ans = 0;
//         for (int i = 1; i <= n; ++i) {
//             vs.insert(i * i);
//         }

//         for (int i = 1; i <= n; ++i) {
//             for (int j = i + 1; j <= n; ++j) {
//                 if (vs.find(i * i + j * j) != vs.end()) {
//                     ans += 2;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int k = sqrt(i * i + j * j);
                if (k <= n && k * k == i * i + j * j) {
                    ans += 2;
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::countTriples)