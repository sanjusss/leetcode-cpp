#pragma once
#include "leetcode.h"

class UnionFind {
public:
    UnionFind(int size) : m_parent(size), m_height(size, 1) {
        for (int i = 0; i < size; ++i) {
            m_parent[i] = i;
        }
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

    int height(int i) {
        return m_height[find(i)];
    }

    void to_union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }

        if (m_height[a] < m_height[b]) {
            swap(a, b);
        }

        m_height[a] += m_height[b];
        m_parent[b] = a;
    }

private:
    vector<int> m_parent;
    vector<int> m_height;
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UnionFind uf(n);
        for (auto& s : allowedSwaps) {
            uf.to_union(s[0], s[1]);
        }

        int ans = n;
        unordered_map<int, vector<int>> groups; 
        for (int i = 0; i < n; ++i) {
            if (uf.height(i) == 1) {
                if (source[i] == target[i]) {
                    --ans;
                }
            }
            else {
                groups[uf.find(i)].push_back(i);
            }
        }

        for (auto& [_, g] : groups) {
            unordered_map<int, int> cnt;
            for (int i : g) {
                ++cnt[source[i]];
            }

            for (int i : g) {
                if (cnt.find(target[i]) == cnt.end()) {
                    continue;
                }

                --ans;
                if (--cnt[target[i]] == 0) {
                    cnt.erase(target[i]);
                }
            }
        }

        return ans;
    }
};