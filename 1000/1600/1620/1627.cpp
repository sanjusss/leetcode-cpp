/*
 * @Author: sanjusss
 * @Date: 2022-02-26 16:03:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-26 16:51:43
 * @FilePath: \1000\1600\1620\1627.cpp
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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        if (threshold < 1) {
            return vector<bool>(queries.size(), true);
        }

        UnionFind uf(n + 1);
        for (int i = threshold + 1; i <= n; ++i) {
            for (int j = i + i; j <= n; j += i) {
                uf.merge(i, j);
            }
        }

        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(uf.find(q[0]) == uf.find(q[1]));
        }

        return ans;
    }
};