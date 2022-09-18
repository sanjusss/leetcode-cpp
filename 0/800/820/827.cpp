/*
 * @Author: sanjusss
 * @Date: 2022-09-18 09:45:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-18 10:16:18
 * @FilePath: \0\800\820\827.cpp
 */
#include "leetcode.h"

// class UnionFind {
// public:
//     UnionFind(int n) : m_parent(n), m_size(n, 1), m_count(n) {
//         for (int i = 0; i < n; ++i) {
//             m_parent[i] = i;
//         }
//     }

//     int count() const {
//         return m_count;
//     }

//     int size(int i) {
//         return m_size[find(i)];
//     }

//     int find(int i) {
//         if (m_parent[i] == i) {
//             return i;
//         }
//         else {
//             m_parent[i] = find(m_parent[i]);
//             return m_parent[i];
//         }
//     }

//     bool merge(int a, int b) {
//         a = find(a);
//         b = find(b);
//         if (a == b) {
//             return false;
//         }

//         if (m_size[a] > m_size[b]) {
//             swap(a, b);
//         }

//         m_parent[a] = b;
//         m_size[b] += m_size[a];
//         --m_count;
//         return true;
//     }

// private:
//     vector<int> m_parent;
//     vector<int> m_size;
//     int m_count;
// };

// class Solution {
// public:
//     int largestIsland(vector<vector<int>>& grid) {
//         static const vector<pair<int, int>> dirs = {
//             { 1, 0 },
//             { -1, 0 },
//             { 0, -1 },
//             { 0, 1 },
//         };
//         int n = grid.size();
//         auto key = [n](int x, int y) {
//             return x * n + y;
//         };
//         UnionFind uf(n * n);
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] == 0) {
//                     continue;
//                 }

//                 int k = key(i, j);
//                 for (auto [dx, dy] : dirs) {
//                     int x = i + dx;
//                     int y = j + dy;
//                     if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0) {
//                         continue;
//                     }

//                     uf.merge(k, key(x, y));
//                 }

//                 ans = max(ans, uf.size(k));
//             }
//         }

//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] == 1) {
//                     continue;
//                 }

//                 unordered_set<int> ks;
//                 int cnt = 1;
//                 for (auto [dx, dy] : dirs) {
//                     int x = i + dx;
//                     int y = j + dy;
//                     if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0) {
//                         continue;
//                     }

//                     int k = uf.find(key(x, y));
//                     if (ks.count(k)) {
//                         continue;
//                     }

//                     cnt += uf.size(k);
//                     ks.insert(k);
//                 }

//                 ans = max(ans, cnt);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 },
        };
        int n = grid.size();
        auto key = [n](int x, int y) { return x * n + y + 1; };
        vector<int> cnt(n * n + 1);
        stack<pair<int, int>> s;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) {
                    continue;
                }

                int k = key(i, j);
                grid[i][j] = -k;
                s.emplace(i, j);
                int c = 1;
                while (!s.empty()) {
                    auto [x, y] = s.top();
                    s.pop();
                    for (auto [dx, dy] : dirs) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] != 1) {
                            continue;
                        }

                        ++c;
                        grid[nx][ny] = -k;
                        s.emplace(nx, ny);
                    }
                }

                cnt[k] = c;
                ans = max(ans, c);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    continue;
                }

                unordered_set<int> ks;
                int c = 1;
                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0) {
                        continue;
                    }

                    int k = -grid[x][y];
                    if (ks.count(k)) {
                        continue;
                    }

                    ks.insert(k);
                    c += cnt[k];
                }

                ans = max(ans, c);
            }
        }

        return ans;
    }
};