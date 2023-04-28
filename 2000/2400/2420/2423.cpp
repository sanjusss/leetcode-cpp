/*
 * @Author: sanjusss
 * @Date: 2023-04-29 06:46:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-29 07:26:42
 * @FilePath: \2000\2400\2420\2423.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool equalFrequency(string word) {
//         vector<int> cnt(26);
//         for (char c : word) {
//             ++cnt[c - 'a'];
//         }

//         unordered_map<int, int> diffs;
//         for (int i : cnt) {
//             if (i > 0) {
//                 ++diffs[i];
//             }
//         }

//         if (diffs.size() == 1) {
//             return diffs.begin()->second == 1|| diffs.begin()->first == 1;
//         }
//         else if (diffs.size() > 2) {
//             return false;
//         }

//         for (auto [d, c] : diffs) {
//             if (c == 1) {
//                 if (diffs.count(d - 1) || d == 1) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> cnt(26);
        for (char c : word) {
            ++cnt[c - 'a'];
        }
        
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == 0) {
                continue;
            }

            int c = cnt[i] - 1;
            bool success = true;
            for (int j = 0; j < 26; ++j) {
                if (i == j || cnt[j] == 0) {
                    continue;
                }

                if (c == 0) {
                    c = cnt[j];
                }
                else if (cnt[j] != c) {
                    success = false;
                    break;
                }
            }

            if (success) {
                return true;
            }
        }

        return false;
    }
};