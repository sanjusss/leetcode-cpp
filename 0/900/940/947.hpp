#pragma once
#include "leetcode.h"

// namespace std {
// template <typename T>
// void hash_combine(std::size_t& seed, T const& key) {
//     std::hash<T> hasher;
//     seed ^= hasher(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
// }

// template <typename T1, typename T2>
// struct hash<std::pair<T1, T2>> {
//     std::size_t operator()(std::pair<T1, T2> const& p) const {
//         std::size_t seed(0);
//         std::hash_combine(seed, p.first);
//         std::hash_combine(seed, p.second);
//         return seed;
//     }
// };
// }  // namespace std

// class UnionFind {
// public:
//     pair<int, int>& find(const pair<int, int>& p) {
//         if (m_parent[p] == p) {
//             return m_parent[p];
//         }
//         else {
//             m_parent[p] = find(m_parent[p]);
//             return m_parent[p];
//         }
//     }

//     void add(const pair<int, int>& p) {
//         auto row = m_row.find(p.first);
//         auto col = m_col.find(p.second);
//         pair<int, int> a;
//         if (row == m_row.end()) {
//             m_row[p.first] = p.second;
//             a = p;
//         }
//         else {
//             a = find({ row->first, row->second });
//         }

//         m_parent[p] = a;
//         pair<int, int> b;
//         if (col == m_col.end()) {
//             m_col[p.second] = p.first;
//             b = p;
//         }
//         else {
//             b = find({ col->second, col->first });
//             m_parent[p] = b;
//         }

//         if (a != b && a != p && b != p) {
//             m_parent[a] = b;
//         }
//     }

// private:
//     unordered_map<pair<int, int>, pair<int, int>> m_parent;
//     unordered_map<int, int> m_row;
//     unordered_map<int, int> m_col;
// };

// class Solution {
// public:
//     int removeStones(vector<vector<int>>& stones) {
//         UnionFind uf;
//         for (auto& s : stones) {
//             uf.add({ s[0], s[1] });
//         }

//         unordered_map<pair<int, int>, int> cnt;
//         for (auto& s : stones) {
//             ++cnt[uf.find({ s[0], s[1] })];
//         }

//         int ans = 0;
//         for (auto& [_, i] : cnt) {
//             ans += i - 1;
//         }

//         return ans;
//     }
// };


class UnionFind {
public:
    int find(int i) {
        auto pos = m_parent.find(i);
        if (pos == m_parent.end()) {
            m_parent[i] = i;
            ++m_count;
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

    void add(int x, int y) {
        x = find((x + 1) << 16);
        y = find(y);
        if (x != y) {
            m_parent[x] = y;
            --m_count;
        }
    }

    int count() {
        return m_count;
    }

private:
    unordered_map<int, int> m_parent;
    int m_count = 0;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf;
        for (auto& s : stones) {
            uf.add(s[0], s[1]);
        }

        return stones.size() - uf.count();
    }
};