/*
 * @Author: sanjusss
 * @Date: 2020-12-06 11:04:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-06 12:10:06
 * @FilePath: \C\C200\C210\C218\4.hpp
 */
#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int minimumIncompatibility(vector<int>& nums, int k) {
//         unordered_map<int, int> cnt;
//         for (int i : nums) {
//             ++cnt[i];
//         }

//         for (auto& p : cnt) {
//             if (p.second > k) {
//                 return -1;
//             }
//         }

//         vector<set<int>> arr(k);
//         int ans = INT_MAX;
//         int maxSize = nums.size() / k;
//         dfs(nums, nums.size() - 1, k, maxSize, arr, ans);
//         return ans;
//     }

// private:
//     void dfs(const vector<int>& nums, int i, int k, int maxSize, vector<set<int>>& arr, int& ans) {
//         if (i == -1) {
//             int res = 0;
//             for (auto& s : arr) {
//                 if (s.empty()) {
//                     return;
//                 }

//                 res += *s.rbegin() - *s.begin();
//             }

//             ans = min(res, ans);
//             return;
//         }
        
//         int v = nums[i];
//         for (int j = 0; j < k; ++j) {
//             auto& s= arr[j];
//             if (s.size() == maxSize || s.find(v) != s.end()) {
//                 continue;
//             }

//             auto p = s.insert(v).first;
//             dfs(nums, i - 1, k, maxSize, arr, ans);
//             s.erase(p);
//         }
//     }
// };

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        
    }
};