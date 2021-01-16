#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        int v = 0;
        for (int i : A) {
            v = ((v << 1) + i) % 5;
            ans.push_back(v == 0);
        }

        return ans;
    }
};