/*
 * @Author: sanjusss
 * @Date: 2022-01-04 15:14:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-04 22:11:18
 * @FilePath: \0\900\910\913.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<pair<int, int>>>> dp(2, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n, { INT_MAX, -1 })));
        vector<vector<vector<bool>>> passed(2, vector<vector<bool>>(n, vector<bool>(n)));
        function<int(int, int, int)> dfs = [&](int round, int mouse, int cat) -> int {
            int r = round % 2;
            if (dp[r][mouse][cat].first <= round && dp[r][mouse][cat].second >= 0) {
                return dp[r][mouse][cat].second;
            }
            else if (passed[r][mouse][cat]) {
                return 0;
            }

            int ans = -1;
            passed[r][mouse][cat] = true;
            if (r) { // 猫行动
                for (int i : graph[cat]) {
                    if (i == 0) {
                        continue;
                    }
                    else if (i == mouse) {
                        ans = 2;
                        break;
                    }

                    int next = dfs(round + 1, mouse, i);
                    if (next == 2) {
                        ans = 2;
                        break;
                    }
                    else if (next == 0) {
                        ans = 0;
                    }
                }
            }
            else { // 鼠行动
                for (int i : graph[mouse]) {
                    if (i == 0) {
                        ans = 1;
                        break;
                    }
                    else if (i == cat) {
                        continue;
                    }

                    int next = dfs(round + 1, i, cat);
                    if (next == 1) {
                        ans = 1;
                        break;
                    }
                    else if (next == 0) {
                        ans = 0;
                    }
                }
            }

            passed[r][mouse][cat] = false;
            if (ans == -1) {
                ans = r ? 1 : 2;
            }

            dp[r][mouse][cat] = { round, ans };
            return ans;
        };

        return dfs(0, 1, 2);
    }
};

TEST(&Solution::catMouseGame)