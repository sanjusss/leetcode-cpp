/*
 * @Author: sanjusss
 * @Date: 2022-11-17 08:37:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-17 08:40:21
 * @FilePath: \0\700\790\792.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            pos[s[i] - 'a'].push_back(i);
        }

        int ans = 0;
        for (auto& w : words) {
            int prev = -1;
            bool succuess = true;
            for (char c : w) {
                int i = c - 'a';
                auto p = upper_bound(pos[i].begin(), pos[i].end(), prev);
                if (p == pos[i].end()) {
                    succuess = false;
                    break;
                }
                else {
                    prev = *p;
                }
            }

            if (succuess) {
                ++ans;
            }
        }

        return ans;
    }
};