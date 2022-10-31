/*
 * @Author: sanjusss
 * @Date: 2022-10-31 09:33:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-31 09:50:12
 * @FilePath: \1000\1600\1610\1617.cpp
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
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> conns(n);
        for (auto& e : edges) {
            conns[e[0] - 1].insert(e[1] - 1);
            conns[e[1] - 1].insert(e[0] - 1);
        }

        vector<vector<int>> dis(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            vector<bool> passed(n);
            passed[i] = true;
            queue<int> q;
            q.push(i);
            for (int d = 0; !q.empty(); ++d) {
                for (int l = q.size(); l > 0; --l) {
                    auto j = q.front();
                    q.pop();
                    dis[i][j] = d;
                    for (int k : conns[j]) {
                        if (passed[k]) {
                            continue;
                        }

                        passed[k] = true;
                        q.push(k);
                    }
                }
            }
        }

        int end = 1 << n;
        vector<int> ans(n - 1);
        for (int mask = 1; mask < end; ++mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt <= 1) {
                continue;
            } 

            UnionFind uf(n);
            int d = 0;
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) {
                    continue;
                }

                for (int j = i + 1; j < n; ++j) {
                    if (!(mask & (1 << j))) {
                        continue;
                    }

                    if (conns[i].count(j)) {
                        uf.merge(i, j);
                    }

                    d = max(d, dis[i][j]);
                }
            }

            if (uf.size(__builtin_ctz(mask)) != cnt) {
                continue;
            }

            ++ans[d - 1];
        }

        return ans;
    }
};