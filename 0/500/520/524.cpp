/*
 * @Author: sanjusss
 * @Date: 2021-09-14 08:30:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-14 08:52:50
 * @FilePath: \0\500\520\524.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     string findLongestWord(string s, vector<string>& dictionary) {
//         sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
//             if (a.size() == b.size()) {
//                 return a < b;
//             }
//             else {
//                 return a.size() > b.size();
//             }
//         });

//         for (auto& w : dictionary) {
//             int i = 0;
//             int j = 0;
//             while (i < s.size() && j < w.size()) {
//                 if (s[i] == w[j]) {
//                     ++j;
//                 }

//                 ++i;
//             }

//             if (j == w.size()) {
//                 return w;
//             }
//         }

//         return string();
//     }
// };

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(26, n));
        dp[n - 1][s[n - 1] - 'a'] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            int p = s[i] - 'a';
            dp[i][p] = i;
            for (int j = 0; j < 26; ++j) {
                if (j != p) {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
            if (a.size() == b.size()) {
                return a < b;
            }
            else {
                return a.size() > b.size();
            }
        });
        for (auto& d : dictionary) {
            int i = 0;
            int j = 0;
            while (i < n && j < d.size() && dp[i][d[j] - 'a'] < n) {
                i = dp[i][d[j] - 'a'] + 1;
                ++j;
            }

            if (j == d.size()) {
                return d;
            }
        }

        return string();
    }
};