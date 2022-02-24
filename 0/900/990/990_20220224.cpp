/*
 * @Author: sanjusss
 * @Date: 2022-02-24 12:51:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-24 12:54:24
 * @FilePath: \0\900\990\990_20220224.cpp
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
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        for (auto& e : equations) {
            if (e[1] == '=') {
                uf.merge(e[0] - 'a', e[3] - 'a');
            }
        }

        for (auto& e : equations) {
            if (e[1] == '!' && uf.find(e[0] - 'a') == uf.find(e[3] - 'a')) {
                return false;
            }
        }

        return true;
    }
};