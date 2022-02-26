/*
 * @Author: sanjusss
 * @Date: 2022-02-26 13:23:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-26 13:39:34
 * @FilePath: \0\300\300\305.cpp
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
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        static const vector<pair<int, int>> dirs = {
            { -1, 0 },
            { 1, 0 },
            { 0, -1 },
            { 0, 1 },
        };
        auto key = [n](int i, int j) { return i * n + j; };
        UnionFind uf(m * n);
        int water = m * n;
        vector<vector<bool>> land(m, vector<bool>(n));
        vector<int> ans;
        for (auto& p : positions) {
            int i = p[0];
            int j = p[1];
            if (!land[i][j]) {
                --water;
                land[i][j] = true;
                int k = key(i, j);
                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x < 0 || x >= m || y < 0 || y >= n || !land[x][y]) {
                        continue;
                    }

                    uf.merge(k, key(x, y));
                }
            }
            
            ans.push_back(uf.count() - water);
        }

        return ans;
    }
};