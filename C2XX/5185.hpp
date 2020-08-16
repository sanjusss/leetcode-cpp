#pragma once
#include "leetcode.h"

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool prev2 = false;
        bool prev1 = false;
        bool cur = false;
        for (int i : arr) {
            prev2 = prev1;
            prev1 = cur;
            cur = (i % 2 == 1);
            if (prev2 && prev1 && cur) {
                return true;
            }
        }

        return false;
    }
};