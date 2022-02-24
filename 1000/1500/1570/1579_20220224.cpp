/*
 * @Author: sanjusss
 * @Date: 2022-02-24 12:31:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-24 12:38:09
 * @FilePath: \1000\1500\1570\1579_20220224.cpp
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufa(n + 1);
        UnionFind ufb(n + 1);
        int ans = 0;
        for (auto& e : edges) {
            if (e[0] == 3) {
                if (ufa.merge(e[1], e[2])) {
                    ufb.merge(e[1], e[2]);
                }
                else {
                    ++ans;
                }
            }
        }

        for (auto& e : edges) {
            if (e[0] == 1) {
                if (!ufa.merge(e[1], e[2])) {
                    ++ans;
                }
            }
            else if (e[0] == 2) {
                if (!ufb.merge(e[1], e[2])) {
                    ++ans;
                }
            }
        }

        if (ufa.count() == 2 && ufb.count() == 2) {
            return ans;
        }
        else {
            return -1;
        }
    }
};

TEST(&Solution::maxNumEdgesToRemove)