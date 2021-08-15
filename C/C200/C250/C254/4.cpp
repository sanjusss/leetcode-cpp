/*
 * @Author: sanjusss
 * @Date: 2021-08-15 10:33:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-15 11:32:53
 * @FilePath: \C\C200\C250\C254\4.cpp
 */
#include "leetcode.h"

class Solution {
    struct UnionFind {
        UnionFind(int n) : parents(n), heights(n, 1) {
            for (int i = 0; i < n; ++i) {
                parents[i] = i;
            }
        }

        int find(int i) {
            if (parents[i] == i) {
                return i;
            }
            else {
                parents[i] = find(parents[i]);
                return parents[i];
            }
        }

        bool merge(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return false;
            }

            if (heights[a] > heights[b]) {
                swap(a, b);
            }

            parents[a] = b;
            heights[b] += heights[a];
            return true;
        }

        vector<int> parents;
        vector<int> heights;
    };

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 }
        };

        int n = row * col;
        vector<bool> isLand(n);
        UnionFind uf(n + 2);
        
        for (int k = n - 1; k >= 0; --k) {
            int i = cells[k][0] - 1;
            int j = cells[k][1] - 1;
            int key = i * col + j;
            isLand[key] = true;
            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= row || y < 0 || y >= col) {
                    continue;
                }

                int z = x * col + y;
                if (isLand[z]) {    
                    uf.merge(key, z);
                }
            }

            if (i == 0) {
                uf.merge(key, n);
            }
            else if (i == row - 1) {
                uf.merge(key, n + 1);
            }

            if (uf.find(n) == uf.find(n + 1)) {
                return k;
            }
        }

        return 0;
    }
};

TEST(&Solution::latestDayToCross)