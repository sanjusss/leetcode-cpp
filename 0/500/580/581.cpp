/*
 * @Author: sanjusss
 * @Date: 2021-08-03 09:52:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-03 11:04:21
 * @FilePath: \0\500\580\581.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         int left = INT_MAX;
//         int right = -1;
//         int n = nums.size();
//         stack<int> s;
//         s.push(0);
//         int maxn = nums[0];
//         for (int i = 1; i < n; ++i) {
//             if (nums[i] > maxn) {
//                 s.push(i);
//                 maxn = nums[i];
//             }
//             else if (nums[i] != maxn){
//                 right = i;
//                 while (!s.empty() && nums[i] < nums[s.top()]) {
//                     left = min(left, s.top());
//                     s.pop();
//                 }
//             }
//         }

//         if (left != INT_MAX) {
//             return right - left + 1;
//         }
//         else {
//             return 0;
//         }
//     }
// };

// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         if (is_sorted(nums.begin(), nums.end())) {
//             return 0;
//         }

//         vector<int> target = nums;
//         sort(target.begin(), target.end());
//         int left = 0;
//         while (target[left] == nums[left]) {
//             ++left;
//         }

//         int right = nums.size() - 1;
//         while (target[right] == nums[right]) {
//             --right;
//         }

//         return right - left + 1;
//     }
// };

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1;
        int right = -1;
        int maxn = INT_MIN;
        int minn = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= maxn) {
                maxn = nums[i];
            }
            else {
                right = i;
            }

            int li = n - 1 - i;
            if (nums[li] <= minn) {
                minn = nums[li];
            }
            else {
                left = li;
            }
        }

        if (left >= 0) {
            return right - left + 1;
        }
        else {
            return 0;
        }
    }
};

TEST(&Solution::findUnsortedSubarray)