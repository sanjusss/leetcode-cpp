#pragma once
#include "leetcode.h"

class UnionFind {
public:
    string_view find(string_view i) {
        auto pos = m_parent.find(i);
        if (pos == m_parent.end()) {
            m_parent[i] = i;
            return i;
        }
        else if (pos->second == i) {
            return i;
        }
        else {
            pos->second = find(pos->second);
            return pos->second;
        }
    }

    void merge(string_view a, string_view b) {
        a = find(a);
        b = find(b);
        if (m_rank[a] > m_rank[b]) {
            swap(a, b);
        }

        m_parent[a] = b;
        ++m_rank[b];
    }
    
private:
    unordered_map<string_view, string_view> m_parent;
    unordered_map<string_view, int> m_rank;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string_view, string_view> names;
        UnionFind uf;
        for (auto& a : accounts) {
            int n = a.size();
            if (n <= 1) {
                continue;
            }

            string_view name = a[0];
            names[a[1]] = name;
            string_view base = uf.find(a[1]);
            for (int i = 1; i < n; ++i) {
                uf.merge(a[i], base);
                names[a[i]] = name;
            }
        }

        unordered_map<string_view, set<string_view>> mails;
        for (auto& a : accounts) {
            for (int i = a.size() - 1; i > 0; --i) {
                mails[uf.find(a[i])].insert(a[i]);
            }
        }

        vector<vector<string>> ans;
        for (auto& [key, vec] : mails) {
            vector<string> ac;
            ac.emplace_back(names[key]);
            for (auto i : vec) {
                ac.emplace_back(i);
            }

            ans.push_back(move(ac));
        }

        return ans;
    }
};