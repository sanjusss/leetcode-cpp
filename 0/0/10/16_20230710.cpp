/*
 * @Author: sanjusss
 * @Date: 2023-07-10 08:55:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-10 09:23:19
 * @FilePath: \0\0\10\16_20230710.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         int n = nums.size();
//         int l = INT_MIN / 2;
//         int u = INT_MAX / 2;
//         set<int> vs;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int sum = nums[i] + nums[j];
//                 auto p = vs.lower_bound(target - sum);
//                 if (p != vs.end()) {
//                     u = min(u, sum + *p);
//                 }
                
//                 if (p != vs.begin()) {
//                     l = max(l, sum + *prev(p));
//                 }
//             }

//             vs.insert(nums[i]);
//         }

//         if (abs(l - target) < abs(u - target)) {
//             return l;
//         }
//         else {
//             return u;
//         }
//     }
// };

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int l = INT_MIN / 2;
        int u = INT_MAX / 2;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    return target;
                }
                else if (sum < target) {
                    l = max(l, sum);
                    ++left;
                }
                else {
                    u = min(u, sum);
                    --right;
                }
            }
        }

        if (abs(l - target) < abs(u - target)) {
            return l;
        }
        else {
            return u;
        }
    }
};