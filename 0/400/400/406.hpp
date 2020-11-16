#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1]; 
            }
            else {
                return a[0] > b[0];
            }
        });

        list<vector<int>> ans;
        for (auto& p : people) {
            auto pos = next(ans.begin(), p[1]);
            ans.insert(pos, p);
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};