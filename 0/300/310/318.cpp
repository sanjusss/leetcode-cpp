/*
 * @Author: sanjusss
 * @Date: 2021-11-17 12:57:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-17 13:14:35
 * @FilePath: \0\300\310\318.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxProduct(vector<string>& words) {
//         int n = words.size();
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             unordered_set cs(words[i].begin(), words[i].end());
//             for (int j = i + 1; j < n; ++j) {
//                 bool success = true;
//                 for (char c : words[j]) {
//                     if (cs.count(c)) {
//                         success = false;
//                         break;
//                     }
//                 }

//                 if (success) {
//                     ans = max(ans, (int)(words[i].size() * words[j].size()));
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bits;
        for (auto &w : words) {
            int bit = 0;
            for (char c : w) {
                bit |= 1 << (c - 'a');
            }

            bits.push_back(bit);
        }

        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!(bits[i] & bits[j])) {
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }

        return ans;
    }
};