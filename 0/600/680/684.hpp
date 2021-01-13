#pragma once
#include "leetcode.h"

class UnionFind {
public:
    UnionFind(int size) : m_height(size, 1), m_parent(size) {
        for (int i = 0; i < size; ++i) {
            m_parent[i] = i;
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

        if (m_height[a] < m_height[b]) {
            swap(a, b);
        }

        m_height[a] += m_height[b];
        m_parent[b] = a;
        return true;
    }

private:
    vector<int> m_height;
    vector<int> m_parent;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        UnionFind uf(N + 1);
        for (auto& edge : edges) {
            if (!uf.merge(edge[0], edge[1])) {
                return edge;
            }
        }

        return {};
    }
};