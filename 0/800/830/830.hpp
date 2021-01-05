#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int start = 0;
        int end = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[start]) {
                if (end - start >= 2) {
                    ans.push_back({ start, end });
                }
                
                start = i;
            }

            end = i;
        }

        if (end - start >= 2) {
            ans.push_back({ start, end });
        }

        return ans;
    }
};