/*
 * @Author: sanjusss
 * @Date: 2022-01-14 08:30:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-14 08:59:57
 * @FilePath: \0\300\370\373.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        auto cmp = [&nums2](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first + nums2[a.second] > b.first + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        int n2 = nums2.size();
        for (int i : nums1) {
            q.emplace(i, 0);
        }

        for (int i = 0; i < k && !q.empty(); ++i) {
            auto [a, j] = q.top();
            q.pop();
            ans.push_back({ a, nums2[j] });
            if (j + 1 < n2) {
                q.emplace(a, j + 1);
            }
        }

        return ans;
    }
};

TEST(&Solution::kSmallestPairs)