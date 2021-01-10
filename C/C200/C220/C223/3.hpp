#pragma once
#include "leetcode.h"

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> diff;
        for (int i = 0; i < n; ++i) {
            if (source[i] != target[i]) {
                diff.push_back(i);
            }
        }

        for (auto& s : allowedSwaps) {
            
        }
    }
};