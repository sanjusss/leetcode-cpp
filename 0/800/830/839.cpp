/*
 * @Author: sanjusss
 * @Date: 2021-01-31 08:39:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-15 11:34:18
 * @FilePath: \0\800\830\839.cpp
 */
#include "leetcode.h"

class Solution {
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

public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int diff = 0;
                for (int k = 0; k < len && diff <= 2; ++k) {
                    if (strs[i][k] != strs[j][k]) {
                        ++diff;
                    }
                }

                if (diff <= 2) {
                    uf.merge(i, j);
                }
            }
        }

        return uf.count();
    }
};

TEST(Solution::numSimilarGroups)