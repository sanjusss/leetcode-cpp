/*
 * @Author: sanjusss
 * @Date: 2023-04-26 08:30:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-26 09:12:44
 * @FilePath: \1000\1000\1030\1031.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
//         int n = nums.size();
//         vector<int> sums(n + 1);
//         for (int i = 0; i < n; ++i) {
//             sums[i + 1] = sums[i] + nums[i];
//         }

//         int ans = 0;
//         for (int i = 0; i + firstLen <= n; ++i) {
//             int f = sums[i + firstLen] - sums[i];
//             for (int j = 0; j + secondLen <= i; ++j) {
//                 int s = sums[j + secondLen] - sums[j];
//                 ans = max(ans, f + s);
//             }

//             for (int j = i + firstLen; j + secondLen <= n; ++j) {
//                 int s = sums[j + secondLen] - sums[j];
//                 ans = max(ans, f + s);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }

        int ans = 0;
        int f = 0;
        int s = 0;
        for (int i = firstLen; i + secondLen <= n; ++i) {
            f = max(f, sums[i] - sums[i - firstLen]);
            s = sums[i + secondLen] - sums[i];
            ans = max(ans, f + s); 
        }

        f = 0;
        s = 0;
        for (int i = secondLen; i + firstLen <= n; ++i) {
            s = max(s, sums[i] - sums[i - secondLen]);
            f = sums[i + firstLen] - sums[i];
            ans = max(ans, f + s); 
        }

        return ans;
    }
};