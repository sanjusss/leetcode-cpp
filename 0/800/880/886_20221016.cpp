/*
 * @Author: sanjusss
 * @Date: 2022-10-16 10:15:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-16 10:30:00
 * @FilePath: \0\800\880\886_20221016.cpp
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> all(n + 1);
        for (auto& dis : dislikes) {
            all[dis[0]].push_back(dis[1]);
            all[dis[1]].push_back(dis[0]);
        }

        UnionFind uf(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (all[i].empty()) {
                continue;
            }

            for (int j = all[i].size() - 1; j > 0; --j) {
                uf.merge(all[i][j], all[i][0]);
            }
            
            if (uf.find(i) == uf.find(all[i][0])) {
                return false;
            }
        }

        return true;
    }
};