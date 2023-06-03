#include "leetcode.h"

// class Solution {
// public:
//     int maxIncreasingCells(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();
//         vector<vector<int>> rows(n, vector<int>(m));
//         for (int j = 0; j < n; ++j) {
//             auto& r = rows[j];
//             iota(r.begin(), r.end(), 0);
//             sort(r.begin(), r.end(), [j, &mat](int a, int b) { return mat[a][j] < mat[b][j]; });
//         }
//         vector<vector<int>> cols(m, vector<int>(n));
//         for (int i = 0; i < m; ++i) {
//             auto& c = cols[i];
//             iota(c.begin(), c.end(), 0);
//             sort(c.begin(), c.end(), [i, &mat](int a, int b) { return mat[i][a] < mat[i][b]; });
//         }

//         queue<tuple<int, int, int>> q;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 auto& c = cols[i];
//                 if (mat[i][j] > mat[i][c[0]]) {
//                     continue;
//                 }

//                 auto& r = rows[j];
//                 if (mat[i][j] > mat[r[0]][j]) {
//                     continue;
//                 }

//                 q.emplace(i, j, 1);
//             }
//         }

//         vector<vector<int>> dis(m, vector<int>(n, 1));
//         int ans = 0;
//         while (!q.empty()) {
//             auto [i, j, d] = q.front();
//             q.pop();
//             if (dis[i][j] != d) {
//                 continue;
//             }

//             ans = max(ans, d);

//             auto& c = cols[i];
//             auto pc =
//                 upper_bound(c.begin(), c.end(), mat[i][j], [&mat, i = i](int val, int b) { return val < mat[i][b];
//                 });
//             for (auto iter = pc; iter != c.end() && mat[i][*pc] == mat[i][*iter]; ++iter) {
//                 int b = *iter;
//                 if (dis[i][b] >= d + 1) {
//                     continue;
//                 }

//                 dis[i][b] = d + 1;
//                 q.emplace(i, b, d + 1);
//             }

//             auto& r = rows[j];
//             auto pr =
//                 upper_bound(r.begin(), r.end(), mat[i][j], [&mat, j = j](int val, int a) { return val < mat[a][j];
//                 });
//             for (auto iter = pr; iter != r.end() && mat[*pr][j] == mat[*iter][j]; ++iter) {
//                 int a = *iter;
//                 if (dis[a][j] >= d + 1) {
//                     continue;
//                 }

//                 dis[a][j] = d + 1;
//                 q.emplace(a, j, d + 1);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<deque<pair<int, int>>> rows(n);
        for (auto& r : rows) {
            r.emplace_back(INT_MIN, 0);
        }

        vector<deque<pair<int, int>>> cols(m);
        for (auto& c : cols) {
            c.emplace_back(INT_MIN, 0);
        }

        vector<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                q.emplace_back(i, j);
            }
        }

        sort(q.begin(), q.end(), [&mat](const pair<int, int>& a, const pair<int, int>& b) {
            return mat[a.first][a.second] < mat[b.first][b.second];
        });

        int ans = 0;
        for (auto [i, j] : q) {
            int d = 1;
            auto& r = rows[j];
            if (r.back().first == mat[i][j]) {
                d = max(d, r.front().second + 1);
            }
            else {
                d = max(d, r.back().second + 1);
            }

            auto& c = cols[i];
            if (c.back().first == mat[i][j]) {
                d = max(d, c.front().second + 1);
            }
            else {
                d = max(d, c.back().second + 1);
            }

            if (r.back().first == mat[i][j]) {
                r.back().second = max(r.back().second, d);
            }
            else {
                r.emplace_back(mat[i][j], d);
            }

            if (r.size() > 2) {
                r.pop_front();
            }

            if (c.back().first == mat[i][j]) {
                c.back().second = max(c.back().second, d);
            }
            else {
                c.emplace_back(mat[i][j], d);
            }

            if (c.size() > 2) {
                c.pop_front();
            }

            ans = max(ans, d);
        }

        return ans;
    }
};

TEST(&Solution::maxIncreasingCells)