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

            m_size[b] += m_size[a];
            m_parent[a] = b;
            --m_count;
            return true;
        }

    private:
        vector<int> m_parent;
        vector<int> m_size;
        int m_count;
    };

public:
    int minSwapsCouples(vector<int>& row) {
        int size = row.size();
        UnionFind uf(size / 2);
        for (int i = 0; i < size; i += 2) {
            uf.merge(row[i] / 2, row[i + 1] / 2);
        }

        return size / 2 - uf.count();
    }
};

TEST(&Solution::minSwapsCouples)