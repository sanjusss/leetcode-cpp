#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        static constexpr int64_t mod = 12345;
        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;
        vector<int64_t> pres(total + 1);
        pres[0] = 1;
        vector<int64_t> suffs(total + 1);
        suffs[total] = 1;
        for (int i = 0; i < total; ++i) {
            int x = i / m; 
            int y = i % m;
            pres[i + 1] = (pres[i] * grid[x][y]) % mod;
        }

        for (int i = total - 1; i >= 0; --i) {
            int x = i / m; 
            int y = i % m;
            suffs[i] = (suffs[i + 1] * grid[x][y]) % mod;
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < total; ++i) {
            int x = i / m; 
            int y = i % m;
            ans[x][y] = (pres[i] * suffs[i + 1]) % mod;
        }

        return ans;
    }
};

TEST(&Solution::constructProductMatrix)