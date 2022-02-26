/*
 * @Author: sanjusss
 * @Date: 2022-02-26 13:56:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-26 14:10:07
 * @FilePath: \0\900\920\924.cpp
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
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (graph[i][j]) {
                    uf.merge(i, j);
                }
            }
        }

        vector<int> cnt(n);
        for (int i : initial) {
            ++cnt[uf.find(i)];
        }

        int diff = 1;
        int ans = -1;
        for (int i : initial) {
            int change = 0;
            if (cnt[uf.find(i)] == 1) {
                change -= uf.size(i);
            }

            if (change < diff) {
                diff = change;
                ans = i;
            }
            else if (change == diff) {
                ans = min(i, ans);
            }
        }

        return ans;
    }
};