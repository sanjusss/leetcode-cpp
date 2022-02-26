/*
 * @Author: sanjusss
 * @Date: 2022-02-26 17:16:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-26 17:40:46
 * @FilePath: \1000\1600\1690\1697.cpp
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
        UnionFind uf(n);
        int edgeSize = edgeList.size();
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[2] != b[2]) {
                return a[2] < b[2];
            }
            else if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            else {
                return a[1] < b[1];
            }
        });
        int qysize = queries.size();
        vector<int> qyi(qysize);
        iota(qyi.begin(), qyi.end(), 0);
        sort(qyi.begin(), qyi.end(), [&queries](int a, int b) {
            if (queries[a][2] != queries[b][2]) {
                return queries[a][2] < queries[b][2];
            }
            else if (queries[a][0] != queries[b][0]) {
                return queries[a][0] < queries[b][0];
            }
            else {
                return queries[a][1] < queries[b][1];
            }
        });
        vector<bool> ans(qysize);
        int ei = 0;
        for (int i : qyi) {
            auto& q = queries[i];
            int a = q[0];
            int b = q[1];
            int limit = q[2];
            if (uf.find(a) == uf.find(b)) {
                ans[i] = true;
                continue;
            }

            while (ei < edgeSize && edgeList[ei][2] < limit) {
                uf.merge(edgeList[ei][0], edgeList[ei][1]);
                ++ei;
            }

            ans[i] = uf.find(a) == uf.find(b);
        }

        return ans;
    }
};