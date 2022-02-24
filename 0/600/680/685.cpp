/*
 * @Author: sanjusss
 * @Date: 2022-02-23 16:19:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-24 12:08:02
 * @FilePath: \0\600\680\685.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
//         int n = edges.size();
//         vector<vector<int>> conns(n + 1);
//         vector<int> inputs(n + 1);
//         for (auto& e : edges) {
//             conns[e[0]].push_back(e[1]);
//             ++inputs[e[1]];
//         }

//         for (int i = n - 1; i >= 0; --i) {
//             int e0 = edges[i][0];
//             int e1 = edges[i][1];
//             --inputs[e1];
//             int root = 0;
//             for (int j = 1; j <= n; ++j) {
//                 if (inputs[j] == 0) {
//                     if (root == 0) {
//                         root = j;
//                     }
//                     else {
//                         root = 0;
//                         break;
//                     }
//                 }
//                 else if (inputs[j] > 1) {
//                     root = 0;
//                     break;
//                 }
//             }

//             if (root > 0) {
//                 queue<int> q;
//                 q.push(root);
//                 int remain = n;
//                 while (!q.empty()) {
//                     int j = q.front();
//                     q.pop();
//                     --remain;
//                     for (int k : conns[j]) {
//                         if (j != e0 || k != e1) {
//                             q.push(k);
//                         }
//                     }
//                 }

//                 if (remain == 0) {
//                     return edges[i];
//                 }
//             }

//             ++inputs[e1];
//         }

//         return {};
//     }
// };

class UnionFind {
public:
    UnionFind(int n) : m_parent(n), m_size(n, 1), m_count(n) {
        for (int i = 0; i < n; ++i) {
            m_parent[i] = i;
        }
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

private:
    vector<int> m_parent;
    vector<int> m_size;
    int m_count;
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> inputs(n + 1, -1);
        for (int i = 0; i < n; ++i) {
            int& in = inputs[edges[i][1]];
            if (in == -1) {
                in = i;
                continue;
            }

            bool isTree = true;
            UnionFind uf(n + 1);
            for (int j = 0; j < n && isTree; ++j) {
                if (j == i) {
                    continue;
                }

                isTree = uf.merge(edges[j][0], edges[j][1]);
            }

            if (isTree) {
                return edges[i];
            }
            else {
                return edges[in];
            }
        }

        UnionFind uf(n + 1);
        for (auto& e : edges) {
            if (!uf.merge(e[0], e[1])) {
                return e;
            }
        }
        
        return {};
    }
};