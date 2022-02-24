/*
 * @Author: sanjusss
 * @Date: 2022-02-24 12:59:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-24 13:02:26
 * @FilePath: \1000\1000\1060\1061.cpp
 */
#include "leetcode.h"

class UnionFind {
public:
    UnionFind(int n) : m_parent(n) {
        iota(m_parent.begin(), m_parent.end(), 0);
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

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a < b) {
            m_parent[b] = a;
        }
        else {
            m_parent[a] = b;
        }
    }

private:
    vector<int> m_parent;
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26);
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            uf.merge(s1[i] - 'a', s2[i] - 'a');
        }

        for (auto& i : baseStr) {
            i = 'a' + uf.find(i - 'a');
        }

        return baseStr;
    }
};