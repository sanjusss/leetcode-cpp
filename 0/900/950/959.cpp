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

    enum Direction {
        TOP = 0,
        RIGHT = 1,
        BOTTOM = 2,
        LEFT = 3
    };

public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        UnionFind uf(n * n * 4);
        //上 0，右 1，下 2，左 3
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '\\') {
                    uf.merge(key(n, TOP, i, j), key(n, RIGHT, i, j));
                    uf.merge(key(n, LEFT, i, j), key(n, BOTTOM, i, j));
                }
                else if (grid[i][j] == '/') {
                    uf.merge(key(n, TOP, i, j), key(n, LEFT, i, j));
                    uf.merge(key(n, RIGHT, i, j), key(n, BOTTOM, i, j));
                }
                else {
                    uf.merge(key(n, TOP, i, j), key(n, RIGHT, i, j));
                    uf.merge(key(n, LEFT, i, j), key(n, RIGHT, i, j));
                    uf.merge(key(n, LEFT, i, j), key(n, BOTTOM, i, j));
                }

                if (j + 1 < n) {
                    uf.merge(key(n, RIGHT, i, j), key(n, LEFT, i, j + 1));
                }

                if (i + 1 < n) {
                    uf.merge(key(n, BOTTOM, i, j), key(n, TOP, i + 1, j));
                }
            }
        }

        return uf.count();
    }

private:
    inline static int key(int n, Direction dir, int x, int y) {
        return n * n * (int)dir + n * x + y;
    }
};

TEST(Solution::regionsBySlashes)