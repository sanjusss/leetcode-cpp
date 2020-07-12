#pragma once
#include "leetcode.h"

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> vc;
        for (int i : nums) {
            ++vc[i];
        }

        int ans = 0;
        for (auto& p : vc) {
            if (p.second > 1) {
                ans += p.second * (p.second - 1) / 2;
            }
        }

        return ans;
    }
};