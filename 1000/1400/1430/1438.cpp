/*
 * @Author: sanjusss
 * @Date: 2021-02-21 10:00:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-21 10:11:50
 * @FilePath: \1000\1400\1430\1438.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        deque<int> small;
        deque<int> large;
        int n = nums.size();
        int left = 0;
        int right = 0;
        while (right < n) {
            while (!small.empty() && small.back() > nums[right]) {
                small.pop_back();
            }

            small.push_back(nums[right]);

            while (!large.empty() && large.back() < nums[right]) {
                large.pop_back();
            }

            large.push_back(nums[right]);

            while (large.front() - small.front() > limit) {
                if (large.front() == nums[left]) {
                    large.pop_front();
                }

                if (small.front() == nums[left]) {
                    small.pop_front();
                }

                ++left;
            }

            ++right;
            ans = max(ans, right - left);
        }

        return ans;
    }
};

TEST(&Solution::longestSubarray)