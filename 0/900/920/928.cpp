/*
 * @Author: sanjusss
 * @Date: 2022-02-26 14:17:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-26 15:59:56
 * @FilePath: \0\900\920\928.cpp
 */
#include "leetcode.h"

class UnionFind {
public:
    UnionFind(int n) : m_parent(n), m_size(n), m_count(n) {
        reset();
    }

    int count() const {
        return m_count;
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

    int size(int i) {
        return m_size[find(i)];
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

    void reset() {
        m_count = m_parent.size();
        iota(m_parent.begin(), m_parent.end(), 0);
        fill(m_size.begin(), m_size.end(), 1);
    }

private:
    vector<int> m_parent;
    vector<int> m_size;
    int m_count;
};

// class Solution {
// public:
//     int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
//         int n = graph.size();
//         UnionFind uf(n);
//         vector<bool> passed(n);
//         int m = INT_MAX;
//         int ans = -1;
//         for (int x : initial) {
//             uf.reset();
//             fill(passed.begin(), passed.end(), false);
//             for (int i = 0; i < n; ++i) {
//                 if (i == x) {
//                     continue;
//                 }

//                 for (int j = i + 1; j < n; ++j) {
//                     if (j != x && graph[i][j]) {
//                         uf.merge(i, j);
//                     }
//                 }
//             }

//             int cnt = 0;
//             for (int y : initial) {
//                 if (x == y || passed[uf.find(y)]) {
//                     continue;
//                 }

//                 passed[uf.find(y)] = true;
//                 cnt += uf.size(y);
//             }

//             if (cnt < m) {
//                 m = cnt;
//                 ans = x;
//             }
//             else if (cnt == m) {
//                 ans = min(ans, x);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<bool> isInitial(n);
        for (int i : initial) {
            isInitial[i] = true;
        }

        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            if (isInitial[i]) {
                continue;
            }

            for (int j = i + 1; j < n; ++j) {
                if (!isInitial[j] && graph[i][j]) {
                    uf.merge(i, j);
                }
            }
        }

        vector<int> affect(n);
        vector<bool> passed(n);
        for (int i = 0; i < n; ++i) {
            if (!isInitial[i]) {
                continue;
            }

            fill(passed.begin(), passed.end(), false);
            for (int j = 0; j < n; ++j) {
                if (!isInitial[j] && graph[i][j] && !passed[uf.find(j)]) {
                    passed[uf.find(j)] = true;
                    ++affect[uf.find(j)];
                }
            }
        }

        int m = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (!isInitial[i]) {
                continue;
            }

            fill(passed.begin(), passed.end(), false);
            int change = 0;
            for (int j = 0; j < n; ++j) {
                if (!isInitial[j] && graph[i][j] && !passed[uf.find(j)] && affect[uf.find(j)] == 1) {
                    passed[uf.find(j)] = true;
                    change -= uf.size(j);
                }
            }

            if (change < m) {
                m = change;
                ans = i;
            }
            else if (change == m) {
                ans = min(ans, i);
            }
        }

        return ans;
    }
};