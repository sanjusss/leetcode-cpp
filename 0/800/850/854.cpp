/*
 * @Author: sanjusss
 * @Date: 2022-09-21 08:28:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-21 09:52:03
 * @FilePath: \0\800\850\854.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int kSimilarity(string s1, string s2) {
//         using qtype = tuple<int, uint64_t>;  // k, state
//         int n = s1.size();
//         uint64_t src = toBits(s1);
//         uint64_t des = toBits(s2);
//         priority_queue<qtype, vector<qtype>, greater<>> q;
//         q.emplace(0, src);
//         unordered_set<uint64_t> used;
//         used.insert(src);
//         while (!q.empty()) {
//             auto [k, cur] = q.top();
//             q.pop();
//             if (cur == des) {
//                 return k;
//             }

//             for (int i = 0; i < n; ++i) {
//                 auto ci = getBit(cur, i);
//                 auto di = getBit(des, i);
//                 if (ci == di) {
//                     continue;
//                 }

//                 for (int j = i + 1; j < n; ++j) {
//                     auto cj = getBit(cur, j);
//                     auto dj = getBit(des, j);
//                     if (cj == dj || (ci != dj && cj != di)) {
//                         continue;
//                     }

//                     auto next = swapBit(cur, i, j);
//                     if (used.count(next)) {
//                         continue;
//                     }

//                     q.emplace(k + 1, next);
//                 }
//             }
//         }

//         return -1;
//     }

// private:
//     static constexpr uint64_t sc_mask = 0b111;
//     static uint64_t setBit(uint64_t src, int i, uint64_t v) {
//         return (src & (~(sc_mask << (i * 3)))) | (v << (i * 3));
//     }

//     static uint64_t getBit(uint64_t src, int i) {
//         return (src >> (i * 3)) & sc_mask;
//     }

//     static uint64_t toBits(const string& s) {
//         uint64_t res = 0;
//         for (char c : s) {
//             res <<= 3;
//             res |= c - 'a';
//         }

//         return res;
//     }

//     static bool isDiff(uint64_t a, uint64_t b, int i) {
//         return getBit(a, i) != getBit(b, i);
//     }

//     static uint64_t swapBit(uint64_t src, int i, int j) {
//         auto a = getBit(src, i);
//         auto b = getBit(src, j);
//         src = setBit(src, i, b);
//         return setBit(src, j, a);
//     }
// };

class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.size();
        uint64_t src = toBits(s1);
        uint64_t des = toBits(s2);
        queue<tuple<int, int, uint64_t>> q;
        q.emplace(0, 0, src);
        unordered_set<uint64_t> used;
        used.insert(src);
        while (!q.empty()) {
            auto [k, i, cur] = q.front();
            q.pop();
            if (cur == des) {
                return k;
            }

            while (getBit(cur, i) == getBit(des, i)) {
                ++i;
            }

            for (int j = i + 1; j < n; ++j) {
                if (getBit(cur, j) == getBit(des, j) || getBit(des, i) != getBit(cur, j)) {
                    continue;
                }

                uint64_t next = swapBit(cur, i, j);
                if (used.insert(next).second == false) {
                    continue;
                }

                q.emplace(k + 1, i + 1, next);
            }
        }

        return -1;
    }

private:
    static constexpr uint64_t sc_mask = 0b111;
    static uint64_t setBit(uint64_t src, int i, uint64_t v) {
        return (src & (~(sc_mask << (i * 3)))) | (v << (i * 3));
    }

    static uint64_t getBit(uint64_t src, int i) {
        return (src >> (i * 3)) & sc_mask;
    }

    static uint64_t toBits(const string& s) {
        uint64_t res = 0;
        for (char c : s) {
            res <<= 3;
            res |= c - 'a';
        }

        return res;
    }

    static uint64_t swapBit(uint64_t src, int i, int j) {
        auto a = getBit(src, i);
        auto b = getBit(src, j);
        src = setBit(src, i, b);
        return setBit(src, j, a);
    }
};