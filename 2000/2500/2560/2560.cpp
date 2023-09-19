/*
 * @Author: sanjusss
 * @Date: 2023-09-19 09:00:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-19 11:25:56
 * @FilePath: \2000\2500\2560\2560.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minCapability(vector<int>& nums, int k) {
//         vector<int> cur(k + 1, INT_MAX / 2);
//         vector<int> pre(k + 1, INT_MAX / 2);
//         cur[0] = 0;
//         pre[0] = 0;
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             int minK = max(k + 1 - (n - i + 1) / 2, 1);
//             int maxK = min(i / 2 + 1, k);
//             auto& nxt = pre;
//             for (int j = maxK; j >= minK; --j) {
//                 nxt[j] = min(cur[j], max(pre[j - 1], nums[i]));
//             }

//             swap(cur, pre);
//         }

//         return cur[k];
//     }
// };

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            int pre = INT_MAX;
            for (int i : nums) {
                if (pre <= mid) {
                    pre = INT_MAX;
                }
                else {
                    if (i <= mid) {
                        ++cnt;
                    }

                    pre = i;
                }
            }

            if (cnt >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};