/*
 * @Author: sanjusss
 * @Date: 2022-07-04 08:02:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-04 08:06:12
 * @FilePath: \0\300\320\323.cpp
 */
#include "leetcode.h"

class UnionFind {
public:
    UnionFind(int n) : m_count(n), m_parent(n), m_size(n, 1) {
        iota(m_parent.begin(), m_parent.end(), 0);
    }

    int find(int i) {
        if (m_parent[i] != i) {
            m_parent[i] = find(m_parent[i]);
        }

        return m_parent[i];
    }

    int count() {
        return m_count;
    }

    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }

        if (m_size[a] < m_size[b]) {
            swap(a, b);
        }

        m_size[a] += m_size[b];
        m_parent[b] = a;
        --m_count;
        return true;
    }

private:
    int m_count;
    vector<int> m_parent;
    vector<int> m_size;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto& e : edges) {
            uf.merge(e[0], e[1]);
        }

        return uf.count();
    }
};