#pragma once
#include "leetcode.h"

class UnionFind {
public:
    UnionFind(int size) : m_arr(size), m_rank(size) {
        for (int i = 0; i < size; ++i) {
            m_arr[i] = i;
        }
    }

    int find(int i) {
        if (m_arr[i] == i) {
            return i;
        }
        else {
            m_arr[i] = find(m_arr[i]);
            return m_arr[i];
        }
    }

    int rank(int i) {
        return m_rank[find(i)];
    }

    void to_union(int a, int b) {
        int ra = rank(a);
        int rb = rank(b);
        if (ra >= rb) {
            m_arr[find(b)] = find(a);
            if (ra == rb) {
                ++m_rank[find(a)];
            }
        }
        else {
            m_arr[find(a)] = find(b);
        }
    }

private:
    vector<int> m_arr;
    vector<int> m_rank;
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        UnionFind uf(n);
        for (auto& p : pairs) {
            uf.to_union(p[0], p[1]);
        }

        unordered_map<int, vector<int>> group;
        for (int i = 0; i < n; ++i) {
            if (uf.rank(i) > 0) {
                group[uf.find(i)].push_back(i);
            }
        }

        priority_queue<char, vector<char>, greater<char>> q;
        for (auto& [_, g] : group) {
            for (int i : g) {
                q.push(s[i]);
            }

            for (int i : g) {
                s[i] = q.top();
                q.pop();
            }
        }

        return s;
    }
};