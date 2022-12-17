/*
 * @Author: sanjusss
 * @Date: 2022-12-14 08:41:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-14 08:50:20
 * @FilePath: \1000\1600\1690\1697_20221214.cpp
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [] (const vector<int>& a, const vector<int> & b) {
            return a[2] > b[2];
        });
        vector<int> qis(queries.size());
        iota(qis.begin(), qis.end(), 0);
        sort(qis.begin(), qis.end(), [&queries](int a, int b) {
            return queries[a][2] < queries[b][2];
        });
        UnionFind uf(n);
        vector<bool> ans(queries.size());
        for (int qi : qis) {
            int a = queries[qi][0];
            int b = queries[qi][1];
            int d = queries[qi][2];
            while (!edgeList.empty() && edgeList.back()[2] < d) {
                uf.merge(edgeList.back()[0], edgeList.back()[1]);
                edgeList.pop_back();
            }

            ans[qi] = uf.find(a) == uf.find(b);
        }

        return ans;
    }
};