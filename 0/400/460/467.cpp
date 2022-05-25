/*
 * @Author: sanjusss
 * @Date: 2022-05-25 11:26:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-25 11:49:02
 * @FilePath: \0\400\460\467.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findSubstringInWraproundString(string p) {
//         unordered_set<int> vs;
//         int i = 0;
//         int n = p.size();
//         while (i < n) {
//             int j = i + 1;
//             while (j < n) {
//                 if (p[j - 1] == 'z') {
//                     if (p[j] != 'a') {
//                         break;
//                     }
//                 }
//                 else if (p[j - 1] + 1 != p[j]) {
//                     break;
//                 }

//                 ++j;
//             }

//             for (int x = i; x < j; ++x) {
//                 int base = (p[x] - 'a') * 1000000;
//                 for (int y = x; y < j; ++y) {
//                     vs.insert(base + y - x);
//                 }
//             }

//             i = j;
//         }

//         return vs.size();
//     }
// };

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26);
        int i = 0;
        int n = p.size();
        while (i < n) {
            int j = i + 1;
            while (j < n) {
                if (p[j - 1] == 'z') {
                    if (p[j] != 'a') {
                        break;
                    }
                }
                else if (p[j - 1] + 1 != p[j]) {
                    break;
                }

                ++j;
            }

            for (int x = i; x < j; ++x) {
                int c = p[x] - 'a';
                cnt[c] = max(cnt[c], j - x);
            }

            i = j;
        }

        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};