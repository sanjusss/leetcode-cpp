/*
 * @Author: sanjusss
 * @Date: 2022-06-27 09:21:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-27 09:28:46
 * @FilePath: \0\200\280\281.cpp
 */
#include "leetcode.h"

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            m_vs.push_back(v1);
        }

        if (!v2.empty()) {
            m_vs.push_back(v2);
        }

        for (int i = 0; i < m_vs.size(); ++i) {
            m_q.emplace(i, 0);
        }
    }

    int next() {
        auto [si, vi] = m_q.front();
        m_q.pop();
        int res = m_vs[si][vi];
        if (++vi < m_vs[si].size()) {
            m_q.emplace(si, vi);
        }

        return res;
    }

    bool hasNext() {
        return !m_q.empty();
    }

private:
    vector<vector<int>> m_vs;
    queue<pair<int, int>> m_q;
};
