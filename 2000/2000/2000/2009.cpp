/*
 * @Author: sanjusss
 * @Date: 2024-04-08 08:57:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-04-08 09:05:20
 * @FilePath: \2000\2000\2000\2009.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> arr;
        for (int i : nums) {
            if (arr.empty() || arr.back() != i) {
                arr.push_back(i);
            }
        }

        int ans = n;
        int m = arr.size();
        int left = 0;
        int right = 0;
        for (int i = 0; i < m; ++i) {
            while (left < i && arr[i] - arr[left] > n - 1) {
                ++left;
            }

            while (right < m && arr[right] - arr[i] <= n - 1) {
                ++right;
            }

            ans = min(ans, n - (i - left + 1));
            ans = min(ans, n - (right - i));
        }

        return ans;
    }
};