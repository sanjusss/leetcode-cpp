/*
 * @Author: sanjusss
 * @Date: 2021-04-10 17:01:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-10 17:37:48
 * @FilePath: \LCP\20210410\6.cpp
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

            m_size[b] += m_size[a];
            m_parent[a] = b;
            --m_count;
            return true;
        }

    private:
        vector<int> m_parent;
        vector<int> m_size;
        int m_count;
    };

public:
    int guardCastle(vector<string>& grid) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 },
        };

        static const int m = 2;
        int n = grid[0].size();
        UnionFind uf(m * n);
        int base = -1;
        int monster = -1;
        int trans = -1;
        int totalEmpty = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                switch (grid[i][j]) {
                    case '#':
                        break;

                    case 'C':
                        base = key(i, j);
                        break;

                    case 'S':
                        if (monster == -1) {
                            monster = key(i, j);
                        }
                        else {
                            uf.merge(monster, key(i, j));
                        }

                        for (auto& [di, dj] : dirs) {
                            int x = i + di;
                            int y = j + dj;
                            if (x < 0 || x >= m || y < 0 || y >= n) {
                                continue;
                            }

                            if (grid[x][y] == '.' || grid[x][y] == '#') {
                                continue;
                            }

                            uf.merge(monster, key(x, y));
                        }

                        break;

                    case 'P':
                        if (trans == -1) {
                            trans = key(i, j);
                        }
                        else {
                            uf.merge(trans, key(i, j));
                        }

                        for (auto& [di, dj] : dirs) {
                            int x = i + di;
                            int y = j + dj;
                            if (x < 0 || x >= m || y < 0 || y >= n) {
                                continue;
                            }

                            if (grid[x][y] == '.' || grid[x][y] == '#') {
                                continue;
                            }

                            uf.merge(trans, key(x, y));
                        }

                        break;

                    case '.':
                    default:
                        ++totalEmpty;
                        break;
                }
            }
        }

        if (monster == -1) {  //没有怪
            return 0;
        }

        if (uf.find(monster) == uf.find(base)) {  //怪直接在基地旁边
            return -1;
        }

        //假如把空地都变成石头，再把这些新增石头变回空地，变回空地的最大值。
        int change = 0;
    }

private:
    static int key(int i, int j) {
        return j * 2 + i;
    }
};