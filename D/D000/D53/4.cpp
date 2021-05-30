/*
 * @Author: sanjusss
 * @Date: 2021-05-29 22:03:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-30 09:47:16
 * @FilePath: \D\D000\D53\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int allMask = (1 << n) - 1;
//         vector<int> cur(1 << n, INT_MAX / 2);
//         cur[0] = 0;
//         vector<int> prev(1 << n);
//         for (int n1 : nums1) {
//             swap(cur, prev);
//             fill(cur.begin(), cur.end(), INT_MAX / 2);
//             for (int i = 0; i < allMask; ++i) {
//                 for (int j = 0; j < n; ++j) {
//                     if (i & (1 << j)) {//i已经包含j了
//                         continue;
//                     }

//                     int next = i | (1 << j);
//                     cur[next] = min(cur[next], prev[i] + (n1 ^ nums2[j]));
//                 }
//             }
//         }

//         return cur.back();
//     }
// };

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int allMask = (1 << n) - 1;
        vector<int> dp(1 << n, INT_MAX / 2);
        dp[0] = 0;
        for (int i = 0; i < allMask; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    continue;
                }

                int next = i | (1 << j);
                dp[next] = min(dp[next], dp[i] + (nums1[__builtin_popcount(i)] ^ nums2[j]));
            }
        }

        return dp.back();
    }
};

TEST(&Solution::minimumXORSum)