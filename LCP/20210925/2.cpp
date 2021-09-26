/*
 * @Author: sanjusss
 * @Date: 2021-09-25 15:01:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-25 15:22:27
 * @FilePath: \LCP\20210925\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> bicycleYard(vector<int>& position, vector<vector<int>>& terrain, vector<vector<int>>& obstacle) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 }
        };

        int m = terrain.size();
        int n = terrain[0].size();

        vector<vector<unordered_set<int>>> passed(m, vector<unordered_set<int>>(n));
        passed[position[0]][position[1]].insert(1);
        queue<tuple<int, int, int>> q;
        q.emplace(position[0], position[1], 1);
        vector<vector<int>> ans;
        while (!q.empty()) {
            auto [i, j, s] = q.front();
            q.pop();
            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                int z = s + (terrain[i][j] - terrain[x][y] - obstacle[x][y]);
                if (z <= 0) {
                    continue;
                }

                if (!passed[x][y].insert(z).second) {
                    continue;
                }

                if (z == 1) {
                    ans.push_back({ x, y });
                }

                q.emplace(x, y, z);
            }
        }

        sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            else {
                return a[0] < b[0];
            }
        });
        return ans;
    }
};