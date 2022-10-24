/*
 * @Author: sanjusss
 * @Date: 2022-10-24 08:36:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-24 09:25:05
 * @FilePath: \0\900\910\915.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int partitionDisjoint(vector<int>& nums) {
//         int n = nums.size();
//         stack<int> s;
//         for (int i = n - 1; i >= 0; --i) {
//             if (s.empty() || s.top() >= nums[i]) {
//                 s.push(nums[i]);
//             }
//         }

//         int maxE = INT_MIN;
//         for (int i = 0; i < n; ++i) {
//             if (!s.empty() && s.top() == nums[i]) {
//                 s.pop();
//             }
            
//             maxE = max(maxE, nums[i]);
//             if (s.empty() || s.top() >= maxE) {
//                 return i + 1;
//             }
//         }

//         return 0;
//     }
// };

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int leftMax = INT_MAX;
        int maxE = INT_MIN;
        for (int i = 0; i < n; ++i) {
            maxE = max(nums[i], maxE);
            if (nums[i] < leftMax) {
                leftMax = maxE;
                ans = i + 1;
            }
        }

        return ans;
    }
};

TEST(&Solution::partitionDisjoint)