#pragma once
#include "leetcode.h"

// class Solution {
//     class UnionFind {
//     public:
//         UnionFind(int size) : m_parent(size), m_size(size), m_total(size) {
//             reset();
//         }

//         void reset() {
//             m_count = m_total;
//             for (int i = 0; i < m_total; ++i) {
//                 m_parent[i] = i;
//                 m_size[i] = 1;
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
//             --m_count;
//             return true;
//         }

//         int count() const {
//             return m_count;
//         }

//     private:
//         vector<int> m_parent;
//         vector<int> m_size;
//         const int m_total;
//         int m_count = 0;
//     };

// public:
//     vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
//         int edgeCount = edges.size();
//         vector<int> indexes(edgeCount);
//         for (int i = 0; i < edgeCount; ++i) {
//             indexes[i] = i;
//         }

//         sort(indexes.begin(), indexes.end(), [&edges](int a, int b) { return edges[a][2] < edges[b][2]; });

//         int minLength = 0;
//         UnionFind uf(n);
//         for (int i : indexes) {
//             auto& e = edges[i];
//             if (uf.merge(e[0], e[1])) {
//                 minLength += e[2];
//             }
//         }

//         vector<vector<int>> ans(2);
//         for (int i : indexes) {
//             uf.reset();

//             //删除边i，无法达到minLength，表明i是关键边。
//             int otherMinLength = 0;
//             for (int j : indexes) {
//                 if (i == j) {
//                     continue;
//                 }

//                 auto& e = edges[j];
//                 if (uf.merge(e[0], e[1])) {
//                     otherMinLength += e[2];
//                 }
//             }

//             if (uf.count() != 1 || otherMinLength != minLength) {
//                 ans[0].push_back(i);
//                 continue;
//             }

//             //强行包含边i，如果到达minLength，且构成树，表面i是非关键边。
//             uf.reset();
//             uf.merge(edges[i][0], edges[i][1]);
//             int withinMinLength = edges[i][2];
//             for (int j : indexes) {
//                 if (i == j) {
//                     continue;
//                 }

//                 auto& e = edges[j];
//                 if (uf.merge(e[0], e[1])) {
//                     withinMinLength += e[2];
//                 }
//             }

//             if (uf.count() == 1 && withinMinLength == minLength) {
//                 ans[1].push_back(i);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
    class UnionFind {
    public:
        UnionFind(int size) : m_parent(size), m_size(size), m_count(size) {
            for (int i = 0; i < size; ++i) {
                m_parent[i] = i;
                m_size[i] = 1;
            }
        }

        int find(int i) {
            if (m_parent[i] == i) {
                return i;
            }
            else {
                m_parent[i] = find(m_parent[i]);
                return m_parent[i];
            }
        }

        bool merge(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return false;
            }

            if (m_size[a] > m_size[b]) {
                swap(a, b);
            }

            m_parent[a] = b;
            m_size[b] += m_size[a];
            --m_count;
            return true;
        }

        int count() const {
            return m_count;
        }

    private:
        vector<int> m_parent;
        vector<int> m_size;
        int m_count = 0;
    };

    class Tarjan {
    public:
        Tarjan(int n, const vector<vector<int>>& conn, const vector<vector<int>>& edgeIds, vector<bool>& keyEdges)
            : m_n(n), m_conn(conn), m_edgeIds(edgeIds), m_keyEdges(keyEdges), m_dfn(n), m_low(n) {
            for (int i = 0; i < n; ++i) {
                if (m_dfn[i] == 0) {
                    tarjan(i, -1);
                }
            }
        }

    private:
        void tarjan(int node, int parent) {
            ++m_time;
            m_dfn[node] = m_time;
            m_low[node] = m_time;
            for (int i = 0; i < m_conn[node].size(); ++i) {
                int next = m_conn[node][i];
                int id = m_edgeIds[node][i];

                if (m_dfn[next] == 0) {
                    tarjan(next, id);
                    m_low[node] = min(m_low[node], m_low[next]);
                    if (m_low[next] > m_dfn[node]) {
                        m_keyEdges[id] = true;
                    }
                }
                else if (id != parent) {
                    m_low[node] = min(m_low[node], m_low[next]);
                }
            }
        }

    private:
        const int m_n;
        const vector<vector<int>>& m_conn;
        const vector<vector<int>>& m_edgeIds;
        vector<bool>& m_keyEdges;
        int m_time = 0;
        vector<int> m_dfn;
        vector<int> m_low;
    };

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int edgeCount = edges.size();
        for (int i = 0; i < edgeCount; ++i) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });

        vector<bool> useless(edgeCount);
        vector<bool> keyEdges(edgeCount);
        UnionFind uf(n);
        for (int i = 0; i < edgeCount;) {
            int j = i + 1;
            while (j < edgeCount && edges[j][2] == edges[i][2]) {
                ++j;
            }

            int cnt = 0;
            unordered_map<int, int> ei2gi;
            for (int k = i; k < j; ++k) {
                auto& e = edges[k];
                int x = uf.find(e[0]);
                int y = uf.find(e[1]);
                if (x == y) {
                    useless[e[3]] = true;
                }
                else {
                    if (ei2gi.find(x) == ei2gi.end()) {
                        ei2gi[x] = cnt++;
                    }

                    if (ei2gi.find(y) == ei2gi.end()) {
                        ei2gi[y] = cnt++;
                    }
                }
            }

            if (cnt > 0) {
                vector<vector<int>> g(cnt);
                vector<vector<int>> gi2ei(cnt);
                for (int k = i; k < j; ++k) {
                    auto& e = edges[k];
                    int x = uf.find(e[0]);
                    int y = uf.find(e[1]);
                    if (x != y) {
                        x = ei2gi[x];
                        y = ei2gi[y];
                        g[x].push_back(y);
                        gi2ei[x].push_back(e[3]);
                        g[y].push_back(x);
                        gi2ei[y].push_back(e[3]);
                    }
                }
                Tarjan(cnt, g, gi2ei, keyEdges);
            }

            for (int k = i; k < j; ++k) {
                auto& e = edges[k];
                uf.merge(e[0], e[1]);
            }

            i = j;
        }

        vector<vector<int>> ans(2);
        for (int i = 0; i < edgeCount; ++i) {
            if (useless[i]) {
                continue;
            }

            if (keyEdges[i]) {
                ans[0].push_back(i);
            }
            else {
                ans[1].push_back(i);
            }
        }

        return ans;
    }
};