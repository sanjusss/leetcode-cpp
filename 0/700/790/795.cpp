/*
 * @Author: sanjusss
 * @Date: 2022-11-24 08:11:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-25 13:40:30
 * @FilePath: \0\700\790\795.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
//         int n = nums.size();
//         int ans = 0;
//         stack<pair<int, int>> s;
//         for (int i = 0; i < n; ++i) {
//             while (!s.empty() && nums[s.top().first] < nums[i]) {
//                 auto [j, l] = s.top();
//                 s.pop();
//                 if (nums[j] >= left && nums[j] <= right) {
//                     ans += (i - j) * l;
//                 }
//             }

//             int l = 0;
//             if (nums[i] >= left && nums[i] <= right) {
//                 if (s.empty()) {
//                     l = i + 1;
//                 }
//                 else {
//                     l = i - s.top().first;
//                 }
//             }

//             s.emplace(i, l);
//         }

//         while (!s.empty()) {
//             auto [i, l] = s.top();
//             s.pop();
//             if (nums[i] >= left && nums[i] <= right) {
//                 ans += (n - i) * l;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int ans = 0;
        int lastIn = -1;
        int lastG = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > right) {
                lastG = i;
            }
            else if (nums[i] >= left) {
                lastIn = i;
            }

            ans += max(0, lastIn - lastG);
        }

        return ans;
    }
};