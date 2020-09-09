#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<vector<vector<int>>> dp(target + 1);
//        sort(candidates.begin(), candidates.end());
//        for (int i : candidates) {
//            if (i > target) {
//                break;
//            }
//
//            int end = target - i;
//            dp[i].push_back({ i });
//            for (int j = 1; j <= end; ++j) {
//                if (dp[j].empty()) {
//                    continue;
//                }
//
//                for (vector<int> k : dp[j]) {
//                    k.emplace_back(i);
//                    dp[j + i].emplace_back(move(k));
//                }
//            }
//        }
//
//        return dp[target];
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<vector<int>> ans;
//        dfs(candidates, target, ans, vector<int>(), 0, 0);
//        return ans;
//    }
//
//private:
//    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> cur, int sum, int i) {
//        if (sum == target) {
//            ans.emplace_back(move(cur));
//            return;
//        }
//        else if (sum > target || i == candidates.size()) {
//            return;
//        }
//
//        cur.push_back(0);
//        for (int j = i; j < candidates.size(); ++j) {
//            sum += candidates[j];
//            cur.back() = candidates[j];
//            dfs(candidates, target, ans, cur, sum, j);
//            sum -= candidates[j];
//        }
//    }
//};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        dfs(candidates, target, ans, vector<int>(), 0, 0);
        return ans;
    }

private:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> cur, int sum, int i) {
        cur.emplace_back(0);
        for (int j = i; j < candidates.size(); ++j) {
            sum += candidates[j];
            if (sum > target) {
                break;
            }

            cur.back() = candidates[j];
            if (sum == target) {
                ans.emplace_back(cur);
            }
            else {
                dfs(candidates, target, ans, cur, sum, j);
            }

            sum -= candidates[j];
        }
    }
};