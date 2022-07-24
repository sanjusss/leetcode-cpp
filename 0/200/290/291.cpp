/*
 * @Author: sanjusss
 * @Date: 2022-06-29 08:56:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-29 09:31:58
 * @FilePath: \0\200\290\291.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        int n = pattern.size();
        int m = s.size();
        if (n > m) {
            return false;
        }

        unordered_map<char, string_view> p2s;
        unordered_map<string_view, char> s2p;
        string_view sv = s;
        function<bool(int,int)> dfs = [&](int pi, int si) -> bool {
            if (pi >= n || si >= m) {
                return pi == n && si == m;
            }

            char c = pattern[pi];
            if (p2s.count(c)) {
                string_view sub = p2s[c];
                if (sub == sv.substr(si, sub.size())) {
                    return dfs(pi + 1, si + sub.size());
                }
                else {
                    return false;
                }
            }

            int maxLen = m - si - (n - 1 - pi);
            for (int len = 1; len <= maxLen; ++len) {
                string_view sub = sv.substr(si, len);
                if (s2p.count(sub)) {
                    continue;
                }

                p2s[c] = sub;
                s2p[sub] = c;
                if (dfs(pi + 1, si + len)) {
                    return true;
                }

                p2s.erase(c);
                s2p.erase(sub);
            }

            return false;
        };

        return dfs(0, 0);
    }
};

TEST(&Solution::wordPatternMatch)