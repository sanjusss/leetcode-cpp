/*
 * @Author: sanjusss
 * @Date: 2022-02-15 12:00:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-15 12:24:16
 * @FilePath: \0\700\780\785_20220215.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> pass(n);
//         queue<int> q;
//         for (int i = 0; i < n; ++i) {
//             if (pass[i]) {
//                 continue;
//             }

//             pass[i] = 1;
//             q.push(i);
//             for (int t = 2; !q.empty(); ++t) {
//                 for (int j = q.size(); j > 0; --j) {
//                     int cur = q.front();
//                     q.pop();
//                     for (int next : graph[cur]) {
//                         if (pass[next]) {
//                             if (pass[next] % 2 != t % 2) {
//                                 return false;
//                             }
//                         }
//                         else {
//                             pass[next] = t;
//                             q.push(next);
//                         }
//                     }
//                 }
//             }
//         }

//         return true;
//     }
// };

struct UnionFind {
    UnionFind(int n) : parent(n), size(n, 1), count(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }

        return parent[i];
    }

    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }

        if (size[a] < size[b]) {
            swap(a, b);
        }

        size[a] += size[b];
        parent[b] = a;
        --count;
        return true;
    }

    vector<int> parent;
    vector<int> size;
    int count;
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = graph[i].size() - 1; j > 0; --j) {
                uf.merge(graph[i][j], graph[i][j - 1]);
                if (uf.find(i) == uf.find(graph[i][j])) {
                    return false;
                }
            }
        }

        return true;
    }
};