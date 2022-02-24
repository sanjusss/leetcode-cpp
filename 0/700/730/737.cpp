/*
 * @Author: sanjusss
 * @Date: 2022-02-24 13:08:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-24 13:15:44
 * @FilePath: \0\700\730\737.cpp
 */
#include "leetcode.h"

class UnionFind {
public:
    string_view find(string_view s) {
        if (m_parent.count(s) && m_parent[s] != s) {
            return m_parent[s] = find(m_parent[s]);
        }
        else {
            return s;
        }
    }

    void merge(string_view a, string_view b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }

        if (m_rank[a] < m_rank[b]) {
            swap(a, b);
        }

        m_parent[b] = a;
        ++m_rank[a];
    }

private:
    unordered_map<string_view, string_view> m_parent;
    unordered_map<string_view, int> m_rank;
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }

        UnionFind uf;
        for (auto& p : similarPairs) {
            uf.merge(p[0], p[1]);
        }

        int n = sentence1.size();
        for (int i = 0; i < n; ++i) {
            if (uf.find(sentence1[i]) != uf.find(sentence2[i])) {
                return false;
            }
        }

        return true;
    }
};