#include "leetcode.h"

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int c = 0;
                int v = grid[i][j];
                if (v <= 0) {
                    ++c;
                    v = -v;
                }

                while (v > 0) {
                    ++c;
                    v /= 10;
                }

                ans[j] = max(ans[j], c);
            }
        }

        return ans;
    }
};