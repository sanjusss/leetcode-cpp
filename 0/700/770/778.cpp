/*
 * @Author: sanjusss
 * @Date: 2021-01-30 09:39:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-30 09:58:41
 * @FilePath: \0\700\770\778.cpp
 */
#include "leetcode.h"

class Solution {
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
            return true;
        }

    private:
        vector<int> m_parent;
        vector<int> m_size;
    };

public:
    int swimInWater(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 }
        };
        

        int n = grid.size();
        int total = n * n;
        vector<tuple<int, int, int>> points;
        points.reserve(total);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                points.emplace_back(grid[i][j], i, j);
            }
        }

        sort(points.begin(), points.end());
        UnionFind uf(total);
        for (const auto& [h, i, j] : points) {
            for (const auto& [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= h) {
                    uf.merge(key(n, i, j), key(n, x, y));
                }
            }

            if (uf.find(0) == uf.find(total - 1)) {
                return h;
            }
        }

        return total - 1;
    }

    inline static int key(int n, int i, int j) {
        return i * n + j;
    }
};

TEST(Solution::swimInWater)