/*
 * @Author: sanjusss
 * @Date: 2020-11-29 10:34:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-29 11:23:36
 * @FilePath: \C\C200\C210\C217\2.hpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> mostCompetitive(vector<int>& nums, int k) {
//         vector<int> ans;
//         auto begin = nums.begin();
//         auto end = nums.end();
//         while (k > 0) {
//             auto pos = min_element(begin, prev(end, --k));
//             ans.push_back(*pos);
//             begin = pos + 1;
//         }

//         return ans;
//     }
// };


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            else {
                return a.first < b.first;
            }
        };
        int n = nums.size();
        set<pair<int, int>, decltype(cmp)> q(cmp);
        vector<decltype(q)::iterator> positions(n);
        int i = 0;
        int prev = 0;
        while (k > 0) {
            while (i < n - k + 1) {
                positions[i] = q.emplace(nums[i], i ).first;                          
                ++i;
            }

            auto p = *q.begin();
            ans.push_back(p.first);
            for (int j = prev; j <= p.second; ++j) {
                q.erase(positions[j]);
            }

            prev = p.second + 1;
            --k;
        }

        return ans;
    }
};