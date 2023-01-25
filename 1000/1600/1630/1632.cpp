/*
 * @Author: sanjusss
 * @Date: 2023-01-25 11:23:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-25 11:58:25
 * @FilePath: \1000\1600\1630\1632.cpp
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
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<int, vector<pair<int, int>>> vs;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vs[matrix[i][j]].emplace_back(i, j);
            }
        }

        vector<vector<int>> ans(m, vector<int>(n));
        vector<int> rowMax(m);
        vector<int> colMax(n);
        for (auto& [_, s] : vs) {
            int len = s.size();
            unordered_map<int, vector<int>> row;
            unordered_map<int, vector<int>> col;
            for (int x = 0; x < len; ++x) {
                row[s[x].first].push_back(x);
                col[s[x].second].push_back(x);
            }

            UnionFind uf(len);
            for (auto& [_, is] : row) {
                for (int x = 1; x < is.size(); ++x) {
                    uf.merge(is[x - 1], is[x]);
                }
            }
            
            for (auto& [_, is] : col) {
                for (int x = 1; x < is.size(); ++x) {
                    uf.merge(is[x - 1], is[x]);
                }
            }

            unordered_map<int, vector<pair<int, int>>> parts;
            for (int x = 0; x < len; ++x) {
                parts[uf.find(x)].push_back(s[x]);
            }

            for (auto& [_, ps] : parts) {
                int index = 0;
                for (auto [i, j] : ps) {
                    index = max(rowMax[i], index);
                    index = max(colMax[j], index);
                }

                ++index;
                for (auto [i, j] : ps) {
                    rowMax[i] = index;
                    colMax[j] = index;
                    ans[i][j] = index;
                }
            }
        }

        return ans;
    }
};