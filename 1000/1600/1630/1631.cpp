#include "leetcode.h"

// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         static vector<pair<int, int>> dirs = {
//             { 1, 0 },
//             { -1, 0 },
//             { 0, -1 },
//             { 0, 1 }
//         };

//         int m = heights.size();
//         int n = heights[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
//         dp[0][0] = 0;
//         vector<vector<bool>> inQ(m, vector<bool>(n));
//         inQ[0][0] = true;
//         queue<pair<int, int>> q;
//         q.emplace(0, 0);
//         while (!q.empty()) {
//             auto [i, j] = q.front();
//             q.pop();
//             inQ[i][j] = false;
//             for (auto [dx, dy] : dirs) {
//                 int x = i + dx;
//                 int y = j + dy;
//                 if (x < 0 || x >= m || y < 0 || y >= n) {
//                     continue;
//                 }

//                 int v = max(abs(heights[x][y] - heights[i][j]), dp[i][j]);
//                 if (v >= dp[x][y]) {
//                     continue;
//                 }

//                 dp[x][y] = v;
//                 if (inQ[x][y]) {
//                     continue;
//                 }

//                 inQ[x][y] = true;
//                 q.emplace(x, y);
//             }
//         }

//         return dp[m - 1][n - 1];
//     }
// };

// class Solution {
//     class UnionFind {
//     public:
//         UnionFind(int n) : m_parent(n), m_size(n, 1), m_count(n) {
//             for (int i = 0; i < n; ++i) {
//                 m_parent[i] = i;
//             }
//         }

//         int find(int i ) {
//             if (m_parent[i] == i) {
//                 return i;
//             }
//             else {
//                 m_parent[i] = find(m_parent[i]);
//                 return m_parent[i];
//             }
//         }

//         bool merge(int a, int b) {
//             a = find(a);
//             b = find(b);
//             if (a == b) {
//                 return false;
//             }

//             if (m_size[a] > m_size[b]) {
//                 swap(a, b);
//             }

//             m_parent[a] = b;
//             m_size[b] += m_size[a];
//             --m_count;
//             return true;
//         }

//         int count() const {
//             return m_count;
//         }

//     private:
//         vector<int> m_parent;
//         vector<int> m_size;
//         int m_count;
//     };

// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int m = heights.size();
//         int n = heights[0].size();
//         vector<tuple<int, int, int>> edges;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (i + 1 < m) {
//                     edges.emplace_back(abs(heights[i][j] - heights[i + 1][j]), n * i + j, n * (i + 1) + j);
//                 }

//                 if (j + 1 < n) {
//                     edges.emplace_back(abs(heights[i][j] - heights[i][j + 1]), n * i + j, n * i + j + 1);
//                 }
//             }
//         }

//         sort(edges.begin(), edges.end());
//         UnionFind uf(m * n);
//         for (auto [path, i, j] : edges) {
//             uf.merge(i, j);
//             if (uf.find(0) == uf.find(m * n - 1)) {
//                 return path;
//             }
//         }

//         return 0;
//     }
// };

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        static vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 }
        };

        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        vector<vector<bool>> passed(m, vector<bool>(n));
        auto cmp = [](const auto& a, const auto& b) {
            return get<0>(a) > get<0>(b);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> q(cmp);
        q.emplace(0, 0, 0);
        while (!q.empty()) {
            auto [d, i, j] = q.top();
            q.pop();
            if (passed[i][j]) {
                continue;
            }
            else {
                passed[i][j] = true;
            }

            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                int v = max(abs(heights[x][y] - heights[i][j]), dist[i][j]);
                if (v >= dist[x][y]) {
                    continue;
                }

                dist[x][y] = v;
                q.emplace(v, x, y);
            }
        }

        return dist[m - 1][n - 1];
    }
};

TEST(Solution::minimumEffortPath)