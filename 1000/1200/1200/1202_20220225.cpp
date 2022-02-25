/*
 * @Author: sanjusss
 * @Date: 2022-02-25 14:55:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-25 15:03:58
 * @FilePath: \1000\1200\1200\1202_20220225.cpp
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

    int size(int i) {
        return m_size[find(i)];
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        UnionFind uf(n);
        for (auto& p : pairs) {
            uf.merge(p[0], p[1]);
        }

        unordered_map<int, priority_queue<char, vector<char>, greater<>>> qs;
        for (int i = 0; i < n; ++i) {
            if (uf.size(i) > 1) {
                qs[uf.find(i)].push(s[i]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (uf.size(i) == 1) {
                continue;
            }

            auto& q = qs[uf.find(i)];
            s[i] = q.top();
            q.pop();
        }

        return s;
    }
};

TEST(&Solution::smallestStringWithSwaps)