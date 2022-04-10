/*
 * @Author: sanjusss
 * @Date: 2022-04-10 10:28:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-10 12:48:57
 * @FilePath: \C\C200\C280\C288\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
//         long long base = 0;
//         sort(flowers.begin(), flowers.end());
//         while (!flowers.empty() && flowers.back() >= target) {
//             base += full;
//             flowers.pop_back();
//         }

//         long long ans = base;
//         while (!flowers.empty()) {
//             long long left = 0;
//             long long right = target - 1;
//             while (left < right) {
//                 long long mid = (left + right + 1) / 2;
//                 long long needs = 0;
//                 for (int i : flowers) {
//                     needs += max<long long>(mid - i, 0);
//                 }

//                 if (needs > newFlowers) {
//                     right = mid - 1;
//                 }
//                 else {
//                     left = mid;
//                 }
//             }

//             ans = max(ans, base + left * partial);
//             if (newFlowers >= target - flowers.back()) {
//                 base += full;
//                 newFlowers -= target - flowers.back();
//                 flowers.pop_back();
//                 ans = max(ans, base);
//             }
//             else {
//                 break;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        long long base = 0;
        sort(flowers.begin(), flowers.end());
        while (!flowers.empty() && flowers.back() >= target) {
            base += full;
            flowers.pop_back();
        }

        vector<long long> sums;
        sums.push_back(0);
        for (int i : flowers) {
            sums.push_back(sums.back() + i);
        }

        long long ans = base;
        while (!flowers.empty()) {
            long long left = 0;
            long long right = target - 1;
            while (left < right) {
                long long mid = (left + right + 1) / 2;
                int p = upper_bound(flowers.begin(), flowers.end(), mid) - flowers.begin();
                if (mid * p - sums[p] > newFlowers) {
                    right = mid - 1;
                }
                else {
                    left = mid;
                }
            }

            ans = max(ans, base + left * partial);
            if (newFlowers >= target - flowers.back()) {
                base += full;
                newFlowers -= target - flowers.back();
                flowers.pop_back();
                ans = max(ans, base);
            }
            else {
                break;
            }
        }

        return ans;
    }
};

TEST(&Solution::maximumBeauty)