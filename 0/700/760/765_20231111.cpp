/*
 * @Author: sanjusss
 * @Date: 2023-11-11 19:56:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-11 19:58:06
 * @FilePath: \0\700\760\765_20231111.cpp
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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            uf.merge(row[i * 2] / 2, row[i * 2 + 1] / 2);
        }

        return n - uf.count();
    }
};

TEST(&Solution::minSwapsCouples)