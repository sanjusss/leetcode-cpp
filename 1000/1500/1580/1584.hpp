#pragma once
#include "leetcode.h"

// class Solution {
//     class UnionFind {
//     public:
//         int64_t find(int64_t i) {
//             auto pos = m_parent.find(i);
//             if (pos == m_parent.end()) {
//                 m_parent[i] = i;
//                 return i;
//             }
//             else if (pos->second == i) {
//                 return i;
//             }
//             else {
//                 pos->second = find(pos->second);
//                 return pos->second;
//             }
//         }

//         int64_t tryFind(int64_t i) {
//             auto pos = m_parent.find(i);
//             if (pos == m_parent.end()) {
//                 return -i;
//             }
//             else if (pos->second == i) {
//                 return i;
//             }
//             else {
//                 pos->second = find(pos->second);
//                 return pos->second;
//             }
//         }

//         void merge(int64_t a, int64_t b) {
//             a = find(a);
//             b = find(b);
//             if (m_rank[a] > m_rank[b]) {
//                 swap(a, b);
//             }

//             m_parent[a] = b;
//             ++m_rank[b];
//         }

//     private:
//         unordered_map<int64_t, int64_t> m_parent;
//         unordered_map<int64_t, int> m_rank;
//     };

// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         multimap<int, pair<int64_t, int64_t>> dis2pts;
//         int n = points.size();
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 dis2pts.emplace(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]),
//                                 make_pair(key(points[i][0], points[i][1]), key(points[j][0], points[j][1])));
//             }
//         }

//         UnionFind uf;
//         int ans = 0;
//         for (auto& [d, pts] : dis2pts) {
//             auto& [a, b] = pts;
//             if (uf.tryFind(a) != uf.tryFind(b)) {
//                 ans += d;
//                 uf.merge(a, b);
//             }
//         }

//         return ans;
//     }

// private:
//     inline static int64_t key(int x, int y) {
//         return ((int64_t)(x + 1000000) << 32) + (int64_t)(y + 1000000);
//     }
// };

// class Solution {
//     class UnionFind {
//     public:
//         UnionFind(int size) : m_parent(size), m_size(size, 1) {
//             for (int i = 0; i < size; ++i) {
//                 m_parent[i] = i;
//             }
//         }

//         int find(int i) {
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
//             return true;
//         }

//     private:
//         vector<int> m_parent;
//         vector<int> m_size;
//     };

// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         vector<tuple<int, int, int>> dis;
//         int n = points.size();
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 dis.emplace_back(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]),
//                                 i, j);
//             }
//         }

//         sort(dis.begin(), dis.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
//             return get<0>(a) < get<0>(b);
//         });
//         UnionFind uf(n);
//         int ans = 0;
//         int cur = 1;
//         for (auto& [d, a, b] : dis) {
//             if (uf.merge(a, b)) {
//                 ans += d;
//                 if (++cur == n) {
//                     break;
//                 }
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         if (n <= 1) {
//             return 0;
//         }

//         vector<vector<int>> conn(n, vector<int>(n));
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
//                 conn[i][j] = dis;
//                 conn[j][i] = dis;
//             }
//         }
        
//         vector<bool> used(n);
//         used[0] = true;
//         vector<int> shortest(n);
//         shortest[0] = INT_MAX;
//         for (int i = 1; i < n; ++i) {
//             shortest[i] = conn[0][i];
//         }

//         int ans = 0;
//         for (int i = 1; i < n; ++i) {
//             auto pos = min_element(shortest.begin(), shortest.end());
//             int cur = pos - shortest.begin();
//             used[cur] = true;
//             ans += *pos;
//             for (int j = 1; j < n; ++j) {
//                 shortest[j] = used[j] ? INT_MAX : min(shortest[j], conn[cur][j]);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) {
            return 0;
        }

        vector<vector<int>> conn(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                conn[i][j] = dis;
                conn[j][i] = dis;
            }
        }
        
        vector<bool> used(n);
        vector<int> shortest(n, INT_MAX);

        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, 0);
        int cnt = 0;
        while (!q.empty() && cnt != n) {
            auto [d, i] = q.top();
            q.pop();
            if (used[i]) {
                continue;
            }

            used[i] = true;
            ans += d;
            ++cnt;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && conn[i][j] < shortest[j]) {
                    shortest[j] = conn[i][j];
                    q.emplace(shortest[j], j);
                }
            }
        }

        return ans;
    }
};