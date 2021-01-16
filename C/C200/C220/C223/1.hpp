#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        int v = first;
        for (int i : encoded) {
            v = v ^ i;
            ans.push_back(v);
        }

        return ans;
    }   
};