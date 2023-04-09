#include "leetcode.h"

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        static constexpr int sc_max = INT_MAX / 2;
        int m = grid.size();
        int n = grid[0].size();

        vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>> cols(n);
        cols[0].emplace(0, 0);
        for (int i = 0; i < m; ++i) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> rq;
            for (int j = 0; j < n; ++j) {
                int t = sc_max;
                auto& cq = cols[j];
                while (!cq.empty() && cq.top().second < i) {
                    cq.pop();
                }

                if (!cq.empty()) {
                    t = min(t, cq.top().first);
                }

                while (!rq.empty() && rq.top().second < j) {
                    rq.pop();
                }

                if (!rq.empty()) {
                    t = min(t, rq.top().first);
                }

                if (t == sc_max) {
                    continue;
                }

                if (i == m - 1 && j == n - 1) {
                    return t + 1;
                }
                else {
                    cq.emplace(t + 1, i + grid[i][j]);
                    rq.emplace(t + 1, j + grid[i][j]);
                }
            }
        }

        return -1;
    }
};

TEST(&Solution::minimumVisitedCells)