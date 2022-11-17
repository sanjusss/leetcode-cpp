/*
 * @Author: sanjusss
 * @Date: 2022-11-17 08:37:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-17 08:51:40
 * @FilePath: \0\700\790\792.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         vector<vector<int>> pos(26);
//         int n = s.size();
//         for (int i = 0; i < n; ++i) {
//             pos[s[i] - 'a'].push_back(i);
//         }

//         int ans = 0;
//         for (auto& w : words) {
//             int prev = -1;
//             bool succuess = true;
//             for (char c : w) {
//                 int i = c - 'a';
//                 auto p = upper_bound(pos[i].begin(), pos[i].end(), prev);
//                 if (p == pos[i].end()) {
//                     succuess = false;
//                     break;
//                 }
//                 else {
//                     prev = *p;
//                 }
//             }

//             if (succuess) {
//                 ++ans;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<pair<int, int>>> qs(26);
        int m = words.size();
        for (int i = 0; i < m; ++i) {
            qs[words[i][0] - 'a'].emplace(i, 0);
        }

        int ans = 0;
        for (char c : s) {
            auto& q = qs[c - 'a'];
            for (int qi = q.size(); qi > 0; --qi) {
                auto [i, j] = q.front();
                q.pop();
                if (++j == words[i].size()) {
                    ++ans;
                }
                else {
                    qs[words[i][j] - 'a'].emplace(i, j);
                }
            }
        }

        return ans;
    }
};