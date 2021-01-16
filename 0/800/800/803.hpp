/*
 * @Author: sanjusss
 * @Date: 2021-01-16 16:32:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-16 22:12:30
 * @FilePath: \0\800\800\803.hpp
 */
#pragma once
#include "leetcode.h"

class UnionFind {
public:
    UnionFind(int n) : m_parent(n), m_size(n, 1) {
        for (int i = 0; i < n; ++i) {
            m_parent[i] = i;
        }
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

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }

        if (m_size[a] > m_size[b]) {
            swap(a, b);
        }

        m_parent[a] = b;
        m_size[b] += m_size[a];
    }

    int size(int i) {
        return m_size[find(i)];
    }

private:
    vector<int> m_parent;
    vector<int> m_size;
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<vector<int>> current = grid;
        for (auto& p : hits) {
            current[p[0]][p[1]] = 0;
        }

        int m = current.size();
        int n = current[0].size();
        int top = m * n;
        UnionFind uf(top + 1);
        for (int j = 0; j < n; ++j) {
            if (current[0][j] == 1) {
                uf.merge(j, top);
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (current[i][j] == 0) {
                    continue;
                }

                if (current[i - 1][j] == 1) {
                    uf.merge(i * n + j, (i - 1) * n + j);
                }

                if (j > 0 && current[i][j - 1] == 1) {
                    uf.merge(i * n + j, i * n + j - 1);
                }
            }
        }

        vector<int> ans(hits.size());
        for (int h = hits.size() - 1; h >= 0; --h) {
            int i = hits[h][0];
            int j = hits[h][1];
            if (grid[i][j] == 0) {
                continue;
            }

            int size = uf.size(top);
            current[i][j] = 1;
            if (i == 0) {
                uf.merge(j, top);
            }

            static const vector<pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            for (auto& dir : dirs) {
                int x = i + dir.first;
                int y = j + dir.second;
                if (x < 0 || x >= m || y < 0 || y >= n || current[x][y] == 0) {
                    continue;
                }

                uf.merge(x * n + y, i * n + j);
            }

            ans[h] = max(0, uf.size(top) - size - 1);
        }

        return ans;
    }
};