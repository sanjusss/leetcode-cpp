/*
 * @Author: sanjusss
 * @Date: 2023-06-12 09:23:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-12 09:45:07
 * @FilePath: \1000\1400\1480\1483.cpp
 */
#include "leetcode.h"

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) : m_parents(n) {
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (parent[i] >= 0) {
                m_parents[i].push_back(parent[i]);
                q.push(i);
            }
        }

        for (int j = 0; !q.empty(); ++j) {
            for (int qi = q.size(); qi > 0; --qi) {
                int i = q.front();
                q.pop();
                if (m_parents[i].size() <= j) {
                    continue;
                }

                int jParent = m_parents[i][j];
                if (m_parents[jParent].size() <= j) {
                    continue;
                }

                m_parents[i].push_back(m_parents[jParent][j]);
                q.push(i);
            }
        }
    }

    int getKthAncestor(int node, int k) {
        if (k == 0) {
            return node;
        }

        int size = m_parents[node].size();
        if (size == 0) {
            return -1;
        }

        while ((1 << (--size)) > k)
            ;
        return getKthAncestor(m_parents[node][size], k - (1 << size));
    }

private:
    vector<vector<int>> m_parents;
};