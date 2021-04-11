/*
 * @Author: sanjusss
 * @Date: 2021-04-10 14:45:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-10 16:49:03
 * @FilePath: \LCP\20210410\3.cpp
 */
#include "leetcode.h"

class Solution {
    struct state {
        int i;
        
    };

public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
        int n = charge.size();
        vector<unordered_map<int, int>> dists(n);
        for (auto& p : paths) {
            dists[p[0]][p[1]] = p[2];
            dists[p[1]][p[0]] = p[2];
        }
    }
};

TEST(&Solution::electricCarPlan)