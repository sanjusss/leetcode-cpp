/*
 * @Author: sanjusss
 * @Date: 2021-09-05 11:43:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-05 12:18:27
 * @FilePath: \C\C200\C250\C257\4.cpp
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
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        UnionFind uf(n);
        int maxEnd = *max_element(nums.begin(), nums.end()) + 1;
        vector<vector<int>> factors(maxEnd);
        for (int i = 0; i < n; ++i) {
            for (int j = sqrt(nums[i]); j > 0; --j) {
                if (nums[i] % j == 0) {
                    factors[j].push_back(i);
                    if (nums[i] / j != j) {
                        factors[nums[i] / j].push_back(i);
                    }
                }
            }
        }

        for (int i = factors.size() - 1; i > 1; --i) {
            auto& fi = factors[i];
            for (int j = fi.size() - 1; j > 0; --j) {
                uf.merge(fi[j], fi[j - 1]);
            }
        }

        vector<int> is(n);
        iota(is.begin(), is.end(), 0);
        sort(is.begin(), is.end(), [&nums](int a, int b) { return nums[a] < nums[b]; });
        for (int i = 0; i < n; ++i) {
            if (uf.find(is[i]) != uf.find(i)) {
                return false;
            }
        }

        return true;
    }
};

TEST(&Solution::gcdSort)