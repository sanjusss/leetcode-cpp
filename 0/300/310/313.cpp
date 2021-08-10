/*
 * @Author: sanjusss
 * @Date: 2021-08-10 16:51:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-10 17:39:22
 * @FilePath: \0\300\310\313.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int nthSuperUglyNumber(int n, vector<int>& primes) {
//         priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> q;
//         q.emplace(1, 0);
//         int size = primes.size();
//         for (int i = 1; i < n; ++i) {
//             auto [v, j] = q.top();
//             q.pop();
//             for (; j < size; ++j) {
//                 q.emplace(v * primes[j], j);
//             }
//         }

//         return q.top().first;
//     }
// };

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 1) {
            return n; 
        }

        vector<int64_t> dp(n + 1);
        dp[1] = 1;
        int m = primes.size();
        vector<int> curs(m, 1);
        vector<int64_t> muls(m);
        for (int i = 2; i <= n; ++i) {
            int64_t number = INT64_MAX;
            for (int j = 0; j < m; ++j) {
                muls[j] = dp[curs[j]] * primes[j];
                number = min(number, muls[j]);
            }

            dp[i] = number;
            for (int j = 0; j < m; ++j) {
                if (muls[j] == number) {
                    ++curs[j];
                }
            }
        }

        return dp[n];
    }
};

TEST(&Solution::nthSuperUglyNumber)