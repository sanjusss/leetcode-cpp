#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n));
        unordered_map<int, unordered_set<int>> cnt;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = cnt[i - j].size();
                cnt[i - j].insert(grid[i][j]);
            }
        }

        cnt.clear();
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = abs(ans[i][j] - (int)(cnt[i - j].size()));
                cnt[i - j].insert(grid[i][j]);
            }
        }

        return ans;
    }
};