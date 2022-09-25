/*
 * @Author: sanjusss
 * @Date: 2022-09-25 10:28:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-25 11:19:04
 * @FilePath: \C\C300\C310\C312\4.cpp
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> nexts(n);
        for (auto& e : edges) {
            if (vals[e[0]] >= vals[e[1]]) {
                nexts[e[0]].push_back(e[1]);
            }

            if (vals[e[1]] >= vals[e[0]]) {
                nexts[e[1]].push_back(e[0]);
            }
        }

        map<int, vector<int>> all;
        for (int i = 0; i < n; ++i) {
            all[vals[i]].push_back(i);
        }

        UnionFind uf(n);
        int ans = 0;
        for (auto& [v, is] : all) {
            for (int i : is) {
                for (int j : nexts[i]) {
                    uf.merge(i, j);
                }
            }

            unordered_map<int, int> cnt;
            for (int i : is) {
                ++cnt[uf.find(i)];
            }

            for (auto [_, c] : cnt) {
                ans += c * (c - 1) / 2;
            }
        }

        return ans + n;
    }
};