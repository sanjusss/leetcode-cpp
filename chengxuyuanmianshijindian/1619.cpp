#include "leetcode.h"

class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        static const vector<pair<int, int>> dirs = {
            { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 },
        };
        vector<int> ans;
        int m = land.size();
        int n = land[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] != 0) {
                    continue;
                }

                int cnt = 0;
                queue<pair<int, int>> q;
                land[i][j] = 1;
                q.emplace(i, j);
                while (!q.empty()) {
                    auto [a, b] = q.front();
                    q.pop();
                    ++cnt;
                    for (auto [dx, dy] : dirs) {
                        int x = a + dx;
                        int y = b + dy;
                        if (x < 0 || x >= m || y < 0 || y >= n || land[x][y] != 0) {
                            continue;
                        }

                        land[x][y] = 1;
                        q.emplace(x, y);
                    }
                }

                ans.push_back(cnt);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};