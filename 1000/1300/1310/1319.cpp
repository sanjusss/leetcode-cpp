/*
 * @Author: sanjusss
 * @Date: 2021-01-23 10:13:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-23 10:51:18
 * @FilePath: \1000\1300\1310\1319.cpp
 */

#include "leetcode.h"

class Solution {
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

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);
        int remains = 0;
        for (auto& c : connections) {
            if (!uf.merge(c[0], c[1])) {
                ++remains;
            }
        }

        if (remains >= uf.count() - 1) {
            return uf.count() - 1;
        }
        else {
            return -1;
        }
    }
};