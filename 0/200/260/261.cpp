/*
 * @Author: sanjusss
 * @Date: 2022-02-14 13:05:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-14 13:19:22
 * @FilePath: \0\200\260\261.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool validTree(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> conns(n);
//         for (auto& e : edges) {
//             conns[e[0]].push_back(e[1]);
//             conns[e[1]].push_back(e[0]);
//         }

//         vector<bool> passed(n);
//         passed[0] = true;
//         queue<pair<int, int>> q;
//         q.emplace(0, -1);
//         while (!q.empty()) {
//             auto [cur, prev] = q.front();
//             q.pop();
//             for (int next : conns[cur]) {
//                 if (next == prev) {
//                     continue;
//                 }
//                 else if (passed[next]) {
//                     return false;
//                 }
//                 else {
//                     passed[next] = true;
//                     q.emplace(next, cur);
//                 }
//             }
//         }

//         for (bool p : passed) {
//             if (!p) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

struct UnionFind {
    UnionFind(int n) : heights(n), parents(n), count(n) {
        iota(parents.begin(), parents.end(), 0);
    }

    int find(int i) {
        if (parents[i] != i) {
            parents[i] = find(parents[i]);
        }

        return parents[i];
    }

    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }

        if (heights[a] < heights[b]) {
            swap(a, b);
        }

        parents[b] = a;
        ++heights[a];
        --count;
        return true;
    }

    vector<int> heights;
    vector<int> parents;
    int count;
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto& e : edges) {
            if (!uf.merge(e[0], e[1])) {
                return false;
            }
        }

        return uf.count == 1;
    }
};