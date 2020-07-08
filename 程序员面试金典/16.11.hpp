#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> ans;
        int sum = shorter * k;
        int step = longer - shorter;
        if (step > 0) {
            for (int i = 0; i < k; ++i) {
                ans.push_back(sum);
                sum += step;
            }
        }
        
        if (k != 0) {
            ans.push_back(sum);
        }

        return ans;
    }
};