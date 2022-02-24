/*
 * @Author: sanjusss
 * @Date: 2022-02-24 12:45:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-24 12:48:53
 * @FilePath: \1000\1100\1100\1101.cpp
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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        UnionFind uf(n);
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        for (auto& l : logs) {
            uf.merge(l[1], l[2]);
            if (uf.count() == 1) {
                return l[0];
            }
        }

        return -1;
    }
};