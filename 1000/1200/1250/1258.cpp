/*
 * @Author: sanjusss
 * @Date: 2022-02-25 10:34:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-25 13:16:58
 * @FilePath: \1000\1200\1250\1258.cpp
 */
#include "leetcode.h"

class Solution {
    struct UnionFind {
        string_view find(string_view s) {
            if (m_parent.count(s)) {
                if (m_parent[s] != s) {
                    m_parent[s] = find(m_parent[s]);
                }
            }
            else {
                m_parent[s] = s;
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
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        UnionFind uf;
        for (auto& p : synonyms) {
            uf.merge(p[0], p[1]);
        }

        unordered_map<string_view, set<string>> words;
        for (auto [i, _] : uf.m_parent) {
            words[uf.find(i)].emplace(i);
        }

        vector<string> ans;
        string cur;
        function<void(string_view)> dfs = [&] (string_view s) {
            if (s.empty()) {
                ans.push_back(cur);
                return;
            }
            
            if (!cur.empty()) {
                cur.push_back(' ');
            }

            int oldSize = cur.size();
            size_t p = s.find(' ');
            string_view sub = p == string_view::npos ? s : s.substr(0, p);
            s = p == string_view::npos ? ""sv : s.substr(p + 1);
            if (uf.m_parent.count(sub)) {
                for (auto& i : words[uf.find(sub)]) {
                    cur += i;
                    dfs(s);
                    cur.resize(oldSize);
                }
            }
            else {
                cur += sub;
                dfs(s);
            }
            
            cur.resize(oldSize);
            if (!cur.empty()) {
                cur.pop_back();
            }
        };
        dfs(text);
        return ans;
    }
};

TEST(&Solution::generateSentences)