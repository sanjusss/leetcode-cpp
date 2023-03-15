#include "leetcode.h"

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> conns(n, vector<bool>(n));
        vector<int> cnt(n);
        for (auto& r : roads) {
            ++cnt[r[0]];
            ++cnt[r[1]];
            conns[r[0]][r[1]] = true;
            conns[r[1]][r[0]] = true;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = cnt[i] + cnt[j] + (conns[i][j] ? -1 : 0);
                ans = max(ans, rank);
            }
        }

        return ans;
    }
};