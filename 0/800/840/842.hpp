#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        if (dfs(S, 0, ans)) {
            return ans;
        }
        else {
            return {};
        }
    }

private:
    bool dfs(const string& S, int i, vector<int>& ans) {
        if (i >= S.size()) {
            return ans.size() >= 3;
        }

        if (S[i] == '0') {
            if (ans.size() >= 2) {
                if (ans[ans.size() - 2] != 0 || ans[ans.size() - 1] != 0) {
                    return false;
                }
            }

            ans.push_back(0);
            if (dfs(S, i + 1, ans)) {
                return true;
            }
            else {
                ans.pop_back();
                return false;
            }
        }

        int64_t v = 0;
        while (i < S.size()) {
            v = v * 10 + S[i++] - '0';
            if (v > INT_MAX) {
                return false;
            }

            if (ans.size() >= 2) {
                int64_t sum = (int64_t)ans[ans.size() - 2] + (int64_t)ans[ans.size() - 1];
                if (sum < v) {
                    return false;
                }
                else if (sum > v) {
                    continue;
                }
            }

            ans.push_back(v);
            if (dfs(S, i, ans)) {
                return true;
            }

            ans.pop_back();
        }

        return false;
    }
};