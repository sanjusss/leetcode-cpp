/*
 * @Author: sanjusss
 * @Date: 2023-09-03 14:41:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-03 15:44:15
 * @FilePath: \1000\1400\1480\1483_20230903.cpp
 */
#include "leetcode.h"

class TreeAncestor {
    static constexpr int sc_maxBits = 16;

public:
    TreeAncestor(int n, vector<int>& parent) {
        m_parents.resize(n, vector<int>(sc_maxBits, -1));
        for (int i = 1; i < n; ++i) {
            m_parents[i][0] = parent[i];
        }

        for (int j = 1; j < sc_maxBits; ++j) {
            for (int i = 1; i < n; ++i) {
                if (m_parents[i][j - 1] >= 0) {
                    m_parents[i][j] = m_parents[m_parents[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = sc_maxBits - 1; i >= 0 && node >= 0; --i) {
            if (k & (1 << i)) {
                node = m_parents[node][i];
            }
        }

        return node;
    }

private:
    vector<vector<int>> m_parents;
};