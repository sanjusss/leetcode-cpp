/*
 * @Author: sanjusss
 * @Date: 2021-02-18 09:40:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-18 11:00:52
 * @FilePath: \0\900\990\995.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minKBitFlips(vector<int>& A, int K) {
//         int n = A.size();
//         int ans = 0;
//         for (int i = K - 1; i < n; ++i) {
//             if (A[i - K + 1] == 1) {
//                 continue;
//             }

//             ++ans;
//             for (int j = i - K + 1; j <= i; ++j) {
//                 if (A[j] == 1) {
//                     A[j] = 0;
//                 }
//                 else {
//                     A[j] = 1;
//                 }
//             }
//         }

//         for (int i = n - K; i < n; ++i) {
//             if (A[i] == 0) {
//                 return -1;
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int minKBitFlips(vector<int>& A, int K) {
//         int n = A.size();
//         vector<bool> subs(n);
//         int ans = 0;
//         int cur = 0;
//         for (int i = 0; i < n; ++i) {
//             if (subs[i]) {
//                 --cur;
//             }

//             A[i] += cur;
//             if (i > n - K || A[i] % 2 == 1) {
//                 continue;
//             }

//             ++A[i];
//             subs[i + K] = true;
//             ++cur;
//             ++ans;
//         }

//         for (int i = n - K + 1; i < n; ++i) {
//             if (A[i] % 2 == 0) {
//                 return -1;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] > 1) {
                --cur;
            }

            if ((A[i] + cur) % 2 == 1) {
                continue;
            }

            if (i > n - K) {
                return -1;
            }

            if (i + K < n) {
                A[i + K] += 2;
            }
            
            ++cur;
            ++ans;
        }

        return ans;
    }
};

TEST(&Solution::minKBitFlips)