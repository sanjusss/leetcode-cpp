/*
 * @Author: sanjusss
 * @Date: 2022-08-07 10:33:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-07 10:38:29
 * @FilePath: \C\C300\C300\C305\2.cpp
 */
#include "leetcode.h"

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

private:
    vector<int> m_parent;
    vector<int> m_size;
    int m_count;
};

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        UnionFind uf(n + 1);
        for (int i : restricted) {
            uf.merge(i, n);
        }

        for (auto &e : edges) {
            if (uf.find(n) == uf.find(e[0]) || uf.find(n) == uf.find(e[1])) {
                continue;
            }

            uf.merge(e[0], e[1]);
        }

        return uf.size(0);
    }
};