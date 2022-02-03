/*
 * @Author: sanjusss
 * @Date: 2022-01-30 10:16:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-30 10:21:03
 * @FilePath: \0\800\880\884.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string_view sv1 = s1;
        int n1 = s1.size();
        unordered_map<string_view, int> cnt1;
        int start = 0;
        for (int i = 0; i <= n1; ++i) {
            if (i == n1 || sv1[i] == ' ') {
                ++cnt1[sv1.substr(start, i - start)];
                start = i + 1;
            }
        }

        string_view sv2 = s2;
        int n2 = s2.size();
        unordered_map<string_view, int> cnt2;
        start = 0;
        for (int i = 0; i <= n2; ++i) {
            if (i == n2 || sv2[i] == ' ') {
                ++cnt2[sv2.substr(start, i - start)];
                start = i + 1;
            }
        }

        vector<string> ans;

        for (auto [s, c] : cnt1) {
            if (c == 1 && !cnt2.count(s)) {
                ans.emplace_back(s);
            }
        }

        for (auto [s, c] : cnt2) {
            if (c == 1 && !cnt1.count(s)) {
                ans.emplace_back(s);
            }
        }

        return ans;
    }
};