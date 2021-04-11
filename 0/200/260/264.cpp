/*
 * @Author: sanjusss
 * @Date: 2021-04-11 12:14:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-11 12:50:40
 * @FilePath: \0\200\260\264.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         set<int64_t> s;
//         s.insert(1);
//         for (int i = 1; i < n; ++i) {
//             int j = *s.begin();
//             s.erase(s.begin());
//             s.insert(j * 2ll);
//             s.insert(j * 3ll);
//             s.insert(j * 5ll);
//         }

//         return *s.begin();
//     }
// };

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = min({ dp[p2] * 2, dp[p3] * 3, dp[p5] * 5 });
            if (dp[i] == dp[p2] * 2) {
                ++p2;
            }
            
            if (dp[i] == dp[p3] * 3) {
                ++p3;
            }
            
            if (dp[i] == dp[p5] * 5) {
                ++p5;
            }
        }

        return dp[n];
    }
};


TEST(&Solution::nthUglyNumber)