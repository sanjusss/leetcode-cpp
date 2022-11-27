/*
 * @Author: sanjusss
 * @Date: 2022-11-27 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-27 11:15:44
 * @FilePath: \C\C300\C320\C321\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int p = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == k) {
                nums[i] = 0;
                p = i;
            }
            else if (nums[i] < k) {
                nums[i] = -1;
            }
            else {
                nums[i] = 1;
            }
        }

        unordered_map<int, int> left;
        int cur = 0;
        for (int i = p; i >= 0; --i) {
            cur += nums[i];
            ++left[cur];
        }

        unordered_map<int, int> right;
        cur = 0;
        for (int i = p; i < n; ++i) {
            cur += nums[i];
            ++right[cur];
        }

        int ans = 0;
        // 0;
        for (auto [i, c] : left) {
            ans += c * right[-i];
        }

        // 1
        for (auto [i, c] : left) {
            ans += c * right[1 - i];
        }

        return ans;
    }
};