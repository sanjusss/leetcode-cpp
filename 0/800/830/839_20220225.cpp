/*
 * @Author: sanjusss
 * @Date: 2022-02-25 16:03:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-25 16:07:36
 * @FilePath: \0\800\830\839_20220225.cpp
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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        auto cmp = [&strs, &m](int a, int b) {
            int d = 0;
            for (int i = 0; i < m; ++i) {
                if (strs[a][i] != strs[b][i] && ++d > 2) {
                    return false;
                }
            }

            return true;
        };

        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (cmp(i, j)) {
                    uf.merge(i, j);
                }
            }
        }

        return uf.count();
    }
};

TEST(&Solution::numSimilarGroups)