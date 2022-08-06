/*
 * @Author: sanjusss
 * @Date: 2022-07-30 07:59:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-30 08:17:31
 * @FilePath: \0\900\950\952.cpp
 */
#include "leetcode.h"

// class UnionFind {
// public:
//     UnionFind(int n) : m_parent(n), m_size(n, 1), m_count(n) {
//         for (int i = 0; i < n; ++i) {
//             m_parent[i] = i;
//         }
//     }

//     int count() const {
//         return m_count;
//     }

//     int find(int i) {
//         if (m_parent[i] == i) {
//             return i;
//         }
//         else {
//             m_parent[i] = find(m_parent[i]);
//             return m_parent[i];
//         }
//     }

//     bool merge(int a, int b) {
//         a = find(a);
//         b = find(b);
//         if (a == b) {
//             return false;
//         }

//         if (m_size[a] > m_size[b]) {
//             swap(a, b);
//         }

//         m_parent[a] = b;
//         m_size[b] += m_size[a];
//         m_maxSize = max(m_maxSize, m_size[b]);
//         --m_count;
//         return true;
//     }

//     int maxSize() const {
//         return m_maxSize;
//     }

// private:
//     vector<int> m_parent;
//     vector<int> m_size;
//     int m_count;
//     int m_maxSize = 1;
// };

// class Solution {
// public:
//     int largestComponentSize(vector<int>& nums) {
//         int n = nums.size();
//         UnionFind uf(n);
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (i != j && gcd(nums[i], nums[j]) > 1) {
//                     uf.merge(i, j);
//                 }
//             }
//         }

//         return uf.maxSize();
//     }
// };

static vector<vector<int>> conns;
static int init = [] () {
    static constexpr int maxNum = 1e5;
    conns.resize(maxNum + 1);
    for (int i = 2; i <= maxNum; ++i) {
        if (conns[i].empty() == false) {
            continue;
        }

        conns[i].push_back(i);
        for (int j = i + i; j <= maxNum; j += i) {
            conns[j].push_back(i);
        }
    }

    return 0;
}();

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
        m_maxSize = max(m_maxSize, m_size[b]);
        --m_count;
        return true;
    }

    int maxSize() const {
        return m_maxSize;
    }

private:
    vector<int> m_parent;
    vector<int> m_size;
    int m_count;
    int m_maxSize = 1;
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        UnionFind uf(n);
        unordered_map<int, int> factors;
        for (int i = 0; i < n; ++i) {
            for (int j : conns[nums[i]]) {
                if (factors.count(j)) {
                    uf.merge(i, factors[j]);
                }
                else {
                    factors[j] = i;
                }
            }
        }

        return uf.maxSize();
    }
};