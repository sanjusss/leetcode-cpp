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
    int minPushBox(vector<vector<char>>& grid) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 },
        };
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        vector<UnionFind> ufs(total, UnionFind(total));
        int obi = 0;
        int obj = 0;
        int osi = 0;
        int osj = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '#') {
                    continue;
                }
                else if (grid[i][j] == 'B') {
                    obi = i;
                    obj = j;
                }
                else if (grid[i][j] == 'S') {
                    osi = i;
                    osj = j;
                }

                auto& uf = ufs[i * n + j];
                for (int x = 0; x < m; ++x) {
                    for (int y = 0; y < n; ++y) {
                        if (grid[x][y] == '#' || (x == i && y == j)) {
                            continue;
                        }

                        for (auto [dx, dy] : dirs) {
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                                continue;
                            }

                            if (nx == i && ny == j) {
                                continue;
                            }

                            if (grid[nx][ny] == '#') {
                                continue;
                            }

                            uf.merge(x * n + y, nx * n + ny);
                        }
                    }
                }
            }
        }

        vector<vector<vector<bool>>> passed(m, vector<vector<bool>>(n, vector<bool>(4)));
        queue<tuple<int, int, int>> q;
        for (int k = 0; k < 4; ++k) {
            int x = obi + dirs[k].first;
            int y = obj + dirs[k].second;
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#') {
                continue;
            }

            auto& uf = ufs[obi * n + obj];
            if (uf.find(x * n + y) == uf.find(osi * n + osj)) {
                q.emplace(obi, obj, k);
                passed[obi][obj][k] = true;
            }
        }

        for (int step = 1; !q.empty(); ++step) {
            for (int qi = q.size(); qi > 0; --qi) {
                auto [i, j, k] = q.front();
                q.pop();
                auto& uf = ufs[i * n + j];
                int pi = i + dirs[k].first;
                int pj = j + dirs[k].second;
                for (int nk = 0; nk < 4; ++nk) {
                    int npi = i + dirs[nk].first;
                    int npj = j + dirs[nk].second;
                    if (npi < 0 || npi >= m || npj < 0 || npj >= n) {
                        continue;
                    }

                    if (uf.find(pi * n + pj) != uf.find(npi * n + npj)) {
                        continue;
                    }

                    int ni = i - dirs[nk].first;
                    int nj = j - dirs[nk].second;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] == '#' || passed[ni][nj][nk]) {
                        continue;
                    }

                    if (grid[ni][nj] == 'T') {
                        return step;
                    }

                    passed[ni][nj][nk] = true;
                    q.emplace(ni, nj, nk);
                }
            }
        }

        return -1;
    }
};

TEST(&Solution::minPushBox)