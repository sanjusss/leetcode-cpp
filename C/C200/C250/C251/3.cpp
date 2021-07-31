/*
 * @Author: sanjusss
 * @Date: 2021-07-25 10:44:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-25 10:57:09
 * @FilePath: \C\C200\C250\C251\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> stus;
        for (auto& s : students) {
            int v = 0;
            for (int i : s) {
                v = (v << 1) | i;
            }

            stus.push_back(v);
        }
        
        vector<int> mens;
        for (auto& s : mentors) {
            int v = 0;
            for (int i : s) {
                v = (v << 1) | i;
            }

            mens.push_back(v);
        }

        int m = students.size();
        int n = students[0].size();
        vector<bool> selected(m);
        int ans = 0;
        dfs(stus, mens, m, n, selected, 0, 0, ans);
        return ans;
    }

private:
    void dfs(const vector<int>& stus, const vector<int>& mens, const int m, const int n, vector<bool>& selected, int i, int cur, int& ans) {
        if (i == m) {
            ans = max(ans, cur);
            return;
        }

        for (int j = 0; j < m; ++j) {
            if (selected[j]) {
                continue;
            }

            selected[j] = true;
            int value = n - __builtin_popcount(stus[i] ^ mens[j]);
            cur += value;
            dfs(stus, mens, m, n, selected, i + 1, cur, ans);
            cur -= value;
            selected[j] = false;
        }
    }
};