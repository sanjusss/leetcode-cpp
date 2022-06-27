/*
 * @Author: sanjusss
 * @Date: 2022-06-27 08:44:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-27 09:14:00
 * @FilePath: \0\500\520\522.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findLUSlength(vector<string>& strs) {
//         unordered_map<string, int> cnt;
//         for (string& s : strs) {
//             int n = s.size();
//             int end = 1 << n;
//             for (int mask = 1; mask < end; ++mask) {
//                 string t;
//                 for (int i = 0; i < n; ++i) {
//                     if (mask & (1 << i)) {
//                         t += s[i];
//                     }
//                 }

//                 ++cnt[t];
//             }
//         }

//         int ans = strs.size() == 1 ? 0 : -1;
//         for (auto& [s, c] : cnt) {
//             if (c == 1 && (int)s.size() > ans) {
//                 ans = s.size();
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            if ((int)strs[i].size() <= ans) {
                continue;
            }

            bool notFound = true;
            for (int j = 0; j < n && notFound; ++j) {
                if (i == j) {
                    continue;
                }

                int si = 0;
                for (int sj = 0; si < strs[i].size() && sj < strs[j].size(); ++sj) {
                    if (strs[i][si] == strs[j][sj]) {
                        ++si;
                    }
                }

                if (si == strs[i].size()) {
                    notFound = false;
                }
            }

            if (notFound) {
                ans = strs[i].size();
            }
        }

        return ans;
    }
};

TEST(&Solution::findLUSlength)