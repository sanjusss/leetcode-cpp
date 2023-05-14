/*
 * @Author: sanjusss
 * @Date: 2023-05-14 10:27:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-14 11:01:20
 * @FilePath: \C\C300\C340\C345\4.cpp
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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        vector<int> conns(n);
        for (auto& e : edges) {
            uf.merge(e[0], e[1]);
            ++conns[e[0]];
            ++conns[e[1]];
        }

        unordered_map<int, int> pts;
        for (int i = 0; i < n; ++i) {
            ++pts[uf.find(i)];
        }

        for (int i = 0; i < n; ++i) {
            auto p = pts.find(uf.find(i));
            if (p == pts.end()) {
                continue;
            }

            if (p->second != conns[i] + 1) {
                pts.erase(p);
            }
        }

        return pts.size();
    }
};