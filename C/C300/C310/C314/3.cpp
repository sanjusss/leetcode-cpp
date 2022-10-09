/*
 * @Author: sanjusss
 * @Date: 2022-10-09 10:43:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-09 10:56:51
 * @FilePath: \C\C300\C310\C314\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string robotWithString(string s) {
        vector<int> cnt(26);
        for (char c : s) {
            ++cnt[c - 'a'];
        }

        string ans;
        string t;
        int ci = 0;
        for (char c : s) {
            while (cnt[ci] == 0) {
                ++ci;
            }

            while (!t.empty() && t.back() - 'a' <= ci) {
                ans.push_back(t.back());
                t.pop_back();
            }

            --cnt[c- 'a'];
            if (ci != c - 'a') {
                t.push_back(c);
                continue;
            }

            ans.push_back(c);
        }

        while (!t.empty()) {
            ans.push_back(t.back());
            t.pop_back();
        }

        return ans;
    }
};

TEST(&Solution::robotWithString)