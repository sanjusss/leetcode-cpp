/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-20 11:05:17
 * @FilePath: \C\C300\C350\C359\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }

        int ans = 0;
        for (auto& [_, arr] : pos) {
            int m = arr.size();
            int left = 0;
            int right = 0;
            while (left < m) {
                while (right < m && arr[right] - arr[left] <= right - left + k) {
                    ++right;
                }

                ans = max(ans, right - left);
                ++left;
            }

        }

        return ans;
    }
};