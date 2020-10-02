#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        dfs(ans, candidates, target, {}, 0);
        return ans;
    }

private:
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, int target, vector<int> cur, int i) {
        int last = INT_MAX;
        int val;
        cur.push_back(0);
        for (int j = i; j < candidates.size(); ++j) {
            val = candidates[j];
            if (val == last) {
                continue;
            }

            if (target < val) {
                break;
            }
            
            last = val;
            cur.back() = val;
            if (target == val) {
                ans.push_back(cur);
            }
            else {
                dfs(ans, candidates, target - val, cur, j + 1);
            }
        }
    }
};