/*
 * @Author: sanjusss
 * @Date: 2022-02-25 15:25:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-25 15:50:50
 * @FilePath: \0\700\720\721_20220225.cpp
 */
#include "leetcode.h"

class Solution {
    struct UnionFind {
        string_view find(string_view s) {
            if (!m_parent.count(s)) {
                m_parent[s] = s;
            }
            else if (m_parent[s] != s) {
                m_parent[s] = find(m_parent[s]);
            }

            return m_parent[s];
        }

        bool merge(string_view a, string_view b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return false;
            }

            if (m_rank[a] < m_rank[b]) {
                swap(a, b);
            }

            m_parent[b] = a;
            ++m_rank[a];
            return true;
        }

        unordered_map<string_view, string_view> m_parent;
        unordered_map<string_view, int> m_rank;
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string_view, string_view> mail2name;
        UnionFind uf;
        for (auto& a : accounts) {
            int n = a.size();
            for (int i = 1; i < n; ++i) {
                mail2name[a[i]] = a[0];
                if (i > 1) {
                    uf.merge(a[1], a[i]);
                }
            }
        }

        unordered_map<string_view, priority_queue<string_view, vector<string_view>, greater<>>> qs;
        for (auto [i, _] : mail2name) {
            qs[uf.find(i)].push(i);
        }

        vector<vector<string>> ans;
        for (auto& [m, q] : qs) {
            vector<string> row;
            row.emplace_back(mail2name[m]);
            while (!q.empty()) {
                row.emplace_back(q.top());
                q.pop();
            }

            ans.push_back(move(row));
        }

        return ans;
    }
};