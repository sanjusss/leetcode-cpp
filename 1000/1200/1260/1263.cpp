/*
 * @Author: sanjusss
 * @Date: 2022-11-01 09:20:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-01 13:52:34
 * @FilePath: \1000\1200\1260\1263.cpp
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
    int minPushBox(vector<vector<char>>& grid) {
        static const vector<pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        int m = grid.size();
        int n = grid[0].size();
        auto key = [n](int i, int j) { return i * n + j; };
        vector<vector<UnionFind*>> ufs(m, vector<UnionFind*>(n));
        auto uf = [&](int i, int j) {
            if (ufs[i][j] != nullptr) {
                return ufs[i][j];
            }

            UnionFind* u = new UnionFind(m * n);
            ufs[i][j] = u;
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    if (grid[x][y] == '#' || (x == i && y == j)) {
                        continue;
                    }

                    for (auto [dx, dy] : dirs) {
                        int nx = dx + x;
                        int ny = dy + y;
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#' || (nx == i && ny == j)) {
                            continue;
                        }

                        u->merge(key(x, y), key(nx, ny));
                    }
                }
            }

            return u;
        };

        vector<vector<vector<bool>>> passed(m, vector<vector<bool>>(n, vector<bool>(4)));
        queue<tuple<int, int, int>> q;
        pair<int, int> box;
        pair<int, int> player;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'B') {
                    box = { i, j };
                }
                else if (grid[i][j] == 'S') {
                    player = { i, j };
                }
            }
        }

        for (int i = 0; i < 4; ++i) {
            int x = box.first + dirs[i].first;
            int y = box.second + dirs[i].second;
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#') {
                continue;
            }

            int des = key(x, y);
            int src = key(player.first, player.second);
            auto u = uf(box.first, box.second);
            if (u->find(src) == u->find(des)) {
                q.emplace(box.first, box.second, i);
                passed[box.first][box.second][i] = true;
            }
        }

        for (int ans = 1; !q.empty(); ++ans) {
            for (int k = q.size(); k > 0; --k) {
                auto [i, j, d] = q.front();
                q.pop();
                int src = key(i + dirs[d].first, j + dirs[d].second);
                i -= dirs[d].first;
                j -= dirs[d].second;
                if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '#') {
                    continue;
                }
                else if (grid[i][j] == 'T') {
                    return ans;
                }

                auto u = uf(i, j);
                for (d = 0; d < 4; ++d) {
                    int x = i + dirs[d].first;
                    int y = j + dirs[d].second;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#' || passed[i][j][d]) {
                        continue;
                    }

                    int des = key(x, y);
                    if (u->find(src) != u->find(des)) {
                        continue;
                    }

                    passed[i][j][d] = true;
                    q.emplace(i, j, d);
                }
            }
        }

        return -1;
    }
};

TEST(&Solution::minPushBox)