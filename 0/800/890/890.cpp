/*
 * @Author: sanjusss
 * @Date: 2022-06-12 10:20:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-12 16:46:19
 * @FilePath: \0\800\890\890.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int n = pattern.size();
        for (auto& s : words) {
            if (s.size() != n) {
                continue;
            }

            vector<int> q2p(26, -1);
            vector<int> p2q(26, -1);
            bool success = true;
            for (int i = 0; i < n; ++i) {
                int q = s[i] - 'a';
                int p = pattern[i] - 'a';
                if (q2p[q] == -1 && p2q[p] == -1) {
                    q2p[q] = p;
                    p2q[p] = q;
                }
                else if (q2p[q] == -1 || p2q[p] == -1 || q2p[q] != p || p2q[p] != q ) {
                    success = false;
                    break;
                }
            }

            if (success) {
                ans.push_back(s);
            }
        }

        return ans;
    }
};