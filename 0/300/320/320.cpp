/*
 * @Author: sanjusss
 * @Date: 2022-07-03 09:25:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-03 09:37:53
 * @FilePath: \0\300\320\320.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<string> generateAbbreviations(string word) {
//         vector<string> charEnds;
//         vector<pair<string, int>> numEnds;
//         charEnds.push_back(""s);
//         for (char i : word) {
//             vector<string> nextCharEnds;
//             vector<pair<string, int>> nextNumEnds;
//             for (auto& s : charEnds) {
//                 nextCharEnds.emplace_back(s + i);
//                 nextNumEnds.emplace_back(s, 1);
//             }

//             for (auto& [s, len] : numEnds) {
//                 nextCharEnds.emplace_back(s + to_string(len) + i);
//                 nextNumEnds.emplace_back(s, len + 1);
//             }

//             charEnds = move(nextCharEnds);
//             numEnds = move(nextNumEnds);
//         }

//         vector<string> ans = move(charEnds);
//         for (auto& [s, i] : numEnds) {
//             ans.push_back(s + to_string(i));
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        int n = word.size();
        int endMask = 1 << n;
        for (int mask = 0; mask < endMask; ++mask) {
            string s;
            int len = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    if (len > 0) {
                        s += to_string(len);
                        len = 0;
                    }

                    s += word[i];
                }
                else {
                    ++len;
                }
            }
            
            if (len > 0) {
                s += to_string(len);
            }

            ans.push_back(move(s));
        }

        return ans;
    }
};