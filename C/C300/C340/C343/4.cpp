/*
 * @Author: sanjusss
 * @Date: 2023-04-30 10:27:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-30 11:30:01
 * @FilePath: \C\C300\C340\C343\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        bool gt = false;
        string ans;
        char maxc = k + 'a';
        function<bool(int)> dfs = [&](int i) -> bool {
            if (i == n) {
                return gt;
            }

            bool oldGt = gt;
            for (char j = gt ? 'a' : (s[i]); j < maxc; ++j) {
                if (i > 0 && ans[i - 1] == j) {
                    continue;
                }

                if (i > 1 && ans[i - 2] == j) {
                    continue;
                }

                if (!gt && j > s[i]) {
                    gt = true;
                }

                ans.push_back(j);
                if (dfs(i + 1)) {
                    return true;
                }

                ans.pop_back();
            }

            gt = oldGt;
            return false;
        };
        if (dfs(0)) {
            return ans;
        }
        else {
            return ""s;
        }
    }
};