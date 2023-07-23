/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-23 16:27:58
 * @FilePath: \C\C300\C350\C355\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     long long countPalindromePaths(vector<int>& parent, string s) {
//         int64_t ans = 0;
//         int n = parent.size();
//         vector<vector<int>> children(n);
//         for (int i = 1; i < n; ++i) {
//             children[parent[i]].push_back(i);
//         }

//         function<unordered_map<int, int64_t>(int)> dfs = [&](int i) -> unordered_map<int, int64_t> {
//             unordered_map<int, int64_t> cur;
//             for (int j : children[i]) {
//                 unordered_map<int, int64_t> pre = dfs(j);
//                 for (auto& [cmask, ccnt] : cur) {
//                     for (auto& [pmask, pcnt] : pre) {
//                         if (__builtin_popcount(cmask ^ pmask) < 2) {
//                             ans += ccnt * pcnt;
//                         }
//                     }
//                 }

//                 for (auto& [mask, cnt] : pre) {
//                     cur[mask] += cnt;
//                     if (__builtin_popcount(mask) < 2) {
//                         ans += cnt;
//                     }
//                 }
//             }

//             if (i == 0) {
//                 return {};
//             }

//             int imask = 1 << (s[i] - 'a');
//             unordered_map<int, int64_t> nxt;
//             for (auto& [cmask, ccnt] : cur) {
//                 nxt[cmask ^ imask] += ccnt;
//             }

//             nxt[imask] += 1;
//             return nxt;
//         };
//         dfs(0);
//         return ans;
//     }
// };

class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        queue<int> q;
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
            if (parent[i] == 0) {
                q.push(i);
            }
        }
        
        int64_t ans = 0;
        vector<int> masks(n);
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int m = masks[parent[i]] ^ (1 << (s[i] - 'a'));
            for (int k = 0; k < 26; ++k) {
                ans += cnt[(1 << k) ^ m];
            }
            
            ans += cnt[m]++;
            masks[i] = m;
            for (int j : children[i]) {
                q.push(j);
            }
        }

        return ans;
    }
};

TEST(&Solution::countPalindromePaths)