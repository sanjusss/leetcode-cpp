/*
 * @Author: sanjusss
 * @Date: 2020-11-28 14:42:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-29 15:36:56
 * @FilePath: \0\400\490\493.hpp
 */
#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         multiset<int64_t> prevs;
//         int ans = 0;
//         for (int64_t i : nums) {
//             ans += distance(prevs.upper_bound(i * 2), prevs.end());
//             prevs.insert(i);
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int ans = 0;
//         int n = nums.size();
//         vector<int64_t> temps(n);
//         vector<int64_t> nums64(nums.begin(), nums.end());
//         int step = 1;
//         while (step < n) {
//             int i = 0;
//             int a;
//             int aEnd;
//             int b;
//             int bEnd;
//             int t = 0;
//             int j;
//             int k;
//             while (i + step < n) {
//                 a = i;
//                 aEnd = a + step;
//                 b = aEnd;
//                 if (b + step <= n) {
//                     bEnd = b + step;
//                 }
//                 else {
//                     bEnd = n;
//                 }

//                 j = a;
//                 k = b;
//                 while (j < aEnd && k < bEnd) {
//                     j = upper_bound(nums64.begin() + j, nums64.begin() + aEnd, nums64[k++] * 2) - nums64.begin();
//                     ans += aEnd - j;
//                 }

//                 i = bEnd;
//                 while (a < aEnd && b < bEnd) {
//                     if (nums64[a] < nums64[b]) {
//                         temps[t++] = nums64[a++];
//                     }
//                     else {
//                         temps[t++] = nums64[b++];
//                     }
//                 }

//                 while (a < aEnd) {
//                     temps[t++] = nums64[a++];
//                 }

//                 while (b < bEnd) {
//                     temps[t++] = nums64[b++];
//                 }
//             }

//             while (i < n) {
//                 temps[t++] = nums64[i++];
//             }

//             swap(temps, nums64);
//             step <<= 1;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> temps(n);
        int step = 1;
        while (step < n) {
            int i = 0;
            int a;
            int aEnd;
            int b;
            int bEnd;
            int t = 0;
            int j;
            int k;
            while (i + step < n) {
                a = i;
                aEnd = a + step;
                b = aEnd;
                if (b + step <= n) {
                    bEnd = b + step;
                }
                else {
                    bEnd = n;
                }

                j = aEnd - 1;
                k = bEnd - 1;
                while (j >= a && k >= b) {
                    if ((int64_t)nums[j] > (int64_t)nums[k] * 2ll) {
                        --j;
                        ans += k - b + 1;
                    }
                    else {
                        --k;
                    }
                }

                i = bEnd;
                while (a < aEnd && b < bEnd) {
                    if (nums[a] < nums[b]) {
                        temps[t++] = nums[a++];
                    }
                    else {
                        temps[t++] = nums[b++];
                    }
                }

                while (a < aEnd) {
                    temps[t++] = nums[a++];
                }

                while (b < bEnd) {
                    temps[t++] = nums[b++];
                }
            }

            while (i < n) {
                temps[t++] = nums[i++];
            }

            swap(temps, nums);
            step <<= 1;
        }

        return ans;
    }
};