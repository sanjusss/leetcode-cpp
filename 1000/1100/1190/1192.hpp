#pragma once
#include "leetcode.h"

class Tarjan {
public:
    Tarjan(int n, const vector<vector<int>>& conn) :
        m_n(n),
        m_conn(conn),
        m_dfn(n),
        m_low(n) {
        tarjan(0, -1);
    }  

    vector<vector<int>>& keyEdges() {
        return m_keyEdges;
    }

private:
    void tarjan(int node, int parent) {
        ++m_time;
        m_dfn[node] = m_time;
        m_low[node] = m_time;
        for (int i : m_conn[node]) {
            if (i == parent) {
                continue;
            }

            if (m_dfn[i] == 0) {
                tarjan(i, node);
                m_low[node] = min(m_low[node], m_low[i]);
                if (m_low[i] > m_dfn[node]) {
                    m_keyEdges.push_back({ i, node });
                }
            }
            else {
                m_low[node] = min(m_low[node], m_low[i]);
            }
        }
    }

private:
    const int m_n;
    const vector<vector<int>>& m_conn;
    vector<vector<int>> m_keyEdges;
    int m_time = 0;
    vector<int> m_dfn;
    vector<int> m_low;
};

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> conn(n);
        for (auto& e : connections) {
            conn[e[0]].push_back(e[1]);
            conn[e[1]].push_back(e[0]);
        }

        Tarjan tarjan(n, conn);
        return move(tarjan.keyEdges());
    }
};