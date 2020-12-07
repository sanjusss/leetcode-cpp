#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                row[j] = ans.back()[j - 1] + ans.back()[j];
            }

            ans.push_back(move(row));
        }

        return ans;
    }
};