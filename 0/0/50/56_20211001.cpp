/*
 * @Author: sanjusss
 * @Date: 2021-10-01 13:24:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-01 14:21:21
 * @FilePath: \0\0\50\56_20211001.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         map<int, int> areas;
//         for (auto& i : intervals) {
//             int b = i[0];
//             int e = i[1];
//             auto pb = areas.upper_bound(b);
//             auto pe = areas.upper_bound(e);
//             auto p = pb; 
//             if (pb == areas.begin() || prev(pb)->second < b) {
//                 p = areas.emplace(b, e).first;
//             }
//             else {
//                 p = prev(pb);
//                 p->second = max(p->second, e);
//             }

//             while (pb != pe) {
//                 p->second = max(pb->second, e);
//                 areas.erase(pb++);
//             }
//         }

//         vector<vector<int>> ans;
//         for (auto [b, e] : areas) {
//             ans.push_back({ b, e });
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (auto& i : intervals) {
            if (ans.empty() || ans.back()[1] < i[0]) {
                ans.push_back(i);
            }
            else {
                ans.back()[1] = max(ans.back()[1], i[1]);
            }
        }

        return ans;
    }
};

TEST(&Solution::merge)