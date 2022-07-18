/*
 * @Author: sanjusss
 * @Date: 2022-07-18 08:50:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-18 09:56:24
 * @FilePath: \0\700\740\749.cpp
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

    int size(int i) {
        return m_size[find(i)];
    }

private:
    vector<int> m_parent;
    vector<int> m_size;
    int m_count;
};

class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
        static const vector<pair<int, int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

        int m = isInfected.size();
        int n = isInfected[0].size();
        auto key = [n](int i, int j) { return i * n + j; };
        auto fromKey = [n](int k, int& i, int& j) {
            i = k / n;
            j = k % n;
        };

        int invaild = m * n;
        UnionFind uf(invaild + 1);
        vector<int> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isInfected[i][j] == 0) {
                    continue;
                }

                int k = key(i, j);
                q.push_back(k);
                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x >= 0 && x < m && y >= 0 && y < n && isInfected[x][y]) {
                        uf.merge(k, key(x, y));
                    }
                }
            }
        }

        int ans = 0;
        while (!q.empty()) {
            unordered_map<int, unordered_set<int>> nexts;
            unordered_map<int, int> cnt;
            for (int k : q) {
                int i;
                int j;
                fromKey(k, i, j);
                k = uf.find(k);
                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x >= 0 && x < m && y >= 0 && y < n && isInfected[x][y] == 0) {
                        nexts[k].insert(key(x, y));
                        ++cnt[k];
                    }
                }
            }

            int block = -1;
            for (auto& [k, n] : nexts) {
                if (block == -1 || n.size() > nexts[block].size()) {
                    block = k;
                }
            }

            if (block == -1) {
                break;
            } 

            ans += cnt[block];
            uf.merge(block, invaild);
            q.clear();
            for (auto& [k, ns] : nexts) {
                if (block == k) {
                    continue;
                }

                for (int kn : ns) {
                    int i;
                    int j;
                    fromKey(kn, i, j);
                    uf.merge(k, kn);
                    if (isInfected[i][j]) {
                        continue;
                    }

                    isInfected[i][j] = 1;
                    q.push_back(kn);
                    for (auto [dx, dy] : dirs) {
                        int x = i + dx;
                        int y = j + dy;
                        if (x < 0 || x >= m || y < 0 || y >= n || isInfected[x][y] == 0) {
                            continue;
                        }

                        int kt = key(x, y);
                        if (uf.find(kt) == uf.find(invaild)) {
                            continue;
                        }

                        uf.merge(kn, kt);
                    }
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::containVirus)