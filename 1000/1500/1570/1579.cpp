#include "leetcode.h"

class Solution {
    class UnionFind {
    public:
        UnionFind(int n) : m_parent(n), m_size(n, 1), m_count(n) {
            for (int i = 0; i < n; ++i) {
                m_parent[i] = i;
            }
        }

        UnionFind(const UnionFind& uf)
            : m_parent(uf.m_parent.begin(), uf.m_parent.end()),
              m_size(uf.m_size.begin(), uf.m_size.end()),
              m_count(uf.m_count) {
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufa(n + 1);
        ufa.merge(0, 1);
        int ans = 0;
        for (auto& e : edges) {
            if (e[0] == 3) {
                if (!ufa.merge(e[1], e[2])) {
                    ++ans;
                }
            }
        }

        UnionFind ufb(ufa);
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

        if (ufa.count() == 1 && ufb.count() == 1) {
            return ans;
        }
        else {
            return -1;
        }
    }
};

TEST(Solution::maxNumEdgesToRemove)