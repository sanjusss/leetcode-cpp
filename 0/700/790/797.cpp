/*
 * @Author: sanjusss
 * @Date: 2021-08-25 09:00:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-25 09:18:30
 * @FilePath: \0\700\790\797.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int des = graph.size() - 1;
        vector<int> path;
        function<void(int)> dfs = [&](int i) {
            if (i == des) {
                ans.push_back(path);
                return;
            }

            for (int j : graph[i]) {
                path.push_back(j);
                dfs(j);
                path.pop_back();
            }
        };

        path.push_back(0);
        dfs(0);
        return ans;
    }
};

TEST_EQUIVALENT(&Solution::allPathsSourceTarget)