/*
 * @Author: sanjusss
 * @Date: 2022-09-06 09:10:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-06 09:33:11
 * @FilePath: \0\800\820\828.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>> pos26(26, vector<int>({-1}));
        for (int i = 0; i < n; ++i) {
            pos26[s[i] - 'A'].push_back(i);
        }

        int ans = 0;
        for (auto &pos : pos26) {
            pos.push_back(n);
            for (int i = pos.size() - 2; i > 0; --i) {
                ans += (pos[i] - pos[i - 1]) * (pos[i + 1] - pos[i]);
            }
        }

        return ans;
    }
};