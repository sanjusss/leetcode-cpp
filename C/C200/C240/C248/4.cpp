/*
 * @Author: sanjusss
 * @Date: 2021-07-04 10:29:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-04 11:41:48
 * @FilePath: \C\C200\C240\C248\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int m = paths.size();
        vector<unordered_map<int, vector<int>>> pointsIndex(m);
        vector<int> cnt(n);
        for (int i = 0; i < m; ++i) {
            auto& p = paths[i];
            int pn = p.size();
            unordered_set<int> diff;
            for (int j = 0; j < pn; ++j) {
                diff.insert(p[j]);
                pointsIndex[i][p[j]].push_back(j);
            }

            for (int j : diff) {
                ++cnt[i];
            }
        }

        unordered_set<int> pts;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == m) {
                pts.insert(i);
            }
        }

        int minPath = 0;
        for (int i = 1; i < m; ++i) {
            if (paths[i].size() < paths[minPath].size()) {
                minPath = i;
            }
        }

        int ans = 0;
        int maxLength = paths[minPath].size();
        for (int i : pts) {
            for (int j : pointsIndex[minPath][i]) {
                int cur = 0;
                bool success = true;
                do {
                    ++cur;
                    
                    if (++j < maxLength) {
                        
                    }
                    else {
                        
                    }
                } while (success);
                ans = max(ans, cur);
            }
        }
        
        return ans;
    }
};