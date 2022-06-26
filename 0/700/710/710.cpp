/*
 * @Author: sanjusss
 * @Date: 2022-06-26 15:54:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-26 16:16:05
 * @FilePath: \0\700\710\710.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     Solution(int n, vector<int>& blacklist) : m_mod(n) {
//         int cnt = 0;
//         sort(blacklist.begin(), blacklist.end());
//         adds.emplace(0, 0);
//         for (int i : blacklist) {
//             adds[i - cnt] = cnt + 1;
//             ++cnt;
//         }

//         m_mod -= cnt;
//     }
    
//     int pick() {
//         int v = rand() % m_mod;
//         auto p = adds.upper_bound(v);
//         if (p != adds.begin()) {
//             v += prev(p)->second;
//         }

//         return v;
//     }

// private:
//     int m_mod;
//     map<int, int> adds;
// };

class Solution {
public:
    Solution(int n, vector<int>& blacklist) : m_mod(n) {
        for (int i : blacklist) {
            m_trans[i] = 0;
        }

        m_mod -= m_trans.size();
        int p = m_mod;
        for (int i : blacklist) {
            if (i < m_mod) {
                while (m_trans.count(p)) {
                    ++p;
                }

                m_trans[i] = p++;
            } 
        }
    }
    
    int pick() {
        int v = rand() % m_mod;
        if (m_trans.count(v)) {
            return m_trans[v];
        }
        else {
            return v;
        }
    }

private:
    int m_mod;
    unordered_map<int, int> m_trans;
};

