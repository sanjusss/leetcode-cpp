/*
 * @Author: sanjusss
 * @Date: 2023-01-05 08:37:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-05 11:24:19
 * @FilePath: \1000\1800\1800\1803.cpp
 */
#include "leetcode.h"

// struct Node {
//     Node* next[2]{ nullptr, nullptr };
//     int cnt = 0;
// };

// class Solution {
//     static constexpr int maxBit = 14;

// public:
//     int countPairs(vector<int>& nums, int low, int high) {
//         m_low = low;
//         m_high = high;
//         int ans = 0;
//         for (int v : nums) {
//             ans += findPairs(v, m_root, maxBit, 0);
//             insert(v);
//         }

//         return ans;
//     }

// private:
//     void insert(int v) {
//         Node* node = m_root;
//         node->cnt++;
//         for (int i = maxBit; i >= 0; --i) {
//             int j = ((1 << i) & v) ? 1 : 0;
//             if (node->next[j] == nullptr) {
//                 node->next[j] = new Node();
//             }

//             node = node->next[j];
//             node->cnt++;
//         }
//     }

//     int findPairs(int v, Node* node, int i, int cur) {
//         if (node == nullptr) {
//             return 0;
//         }

//         if (cur >= m_low && cur + (1 << (i + 1)) - 1 <= m_high) {
//             return node->cnt;
//         }
//         else if (cur + (1 << (i + 1)) - 1 < m_low || cur > m_high) {
//             return 0;
//         }

//         int b = ((1 << i) & v) ? 1 : 0;
//         return findPairs(v, node->next[b], i - 1, cur) + findPairs(v, node->next[1 - b], i - 1, cur + (1 << i));
//     }

// private:
//     Node* m_root = new Node();
//     int m_low;
//     int m_high;
// };

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        unordered_map<int, int> cnt;
        for (int i : nums) {
            ++cnt[i];
        }

        int ans = 0;
        for (++high; high > 0; high >>= 1, low >>= 1) {
            unordered_map<int, int> next;
            for (auto [v, c] : cnt) {
                if ((high & 1) && cnt.count(v ^ (high - 1))) {
                    ans += c * cnt[v ^ (high - 1)];
                }

                if ((low & 1) && cnt.count(v ^ (low - 1))) {
                    ans -= c * cnt[v ^ (low - 1)];
                }

                next[v >> 1] += c;
            }

            swap(cnt, next);
        }

        return ans / 2;
    }
};