/*
 * @Author: sanjusss
 * @Date: 2023-10-15 10:38:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-10-15 10:48:02
 * @FilePath: \C\C300\C360\C367\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string_view ans;
        vector<int> pos;
        string_view sv = s;
        int n = sv.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != '1') {
                continue;
            }

            pos.push_back(i);
            if (pos.size() < k) {
                continue;
            }

            string_view cur = sv.substr(pos[pos.size() - k], i - pos[pos.size() - k] + 1);
            if (ans.empty() || cur.size() < ans.size() || (cur.size() == ans.size() && cur < ans)) {
                ans = cur;
            }
        }

        return string(ans);
    }
};