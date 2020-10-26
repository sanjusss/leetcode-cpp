#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         multiset<int> vs(nums.begin(), nums.end());
//         vector<int> ans;
//         for (int i : nums) {
//             ans.push_back(distance(vs.begin(), vs.lower_bound(i)));
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(102, 0);
        for (int i : nums) {
            ++cnt[i + 1];
        }

        for (int i = 1; i < 102; ++i) {
            cnt[i] += cnt[i - 1];
        }

        vector<int> ans;
        for (int i : nums) {
            ans.push_back(cnt[i]);
        }

        return ans;
    }
};