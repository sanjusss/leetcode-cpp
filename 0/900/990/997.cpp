/*
 * @Author: sanjusss
 * @Date: 2021-12-19 09:02:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-19 09:08:51
 * @FilePath: \0\900\990\997.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> has(n + 1);
        vector<int> cnt(n + 1);
        for (auto& t : trust) {
            ++cnt[t[1]];
            has[t[0]] = true;
        }

        for (int i = 1; i <= n; ++i) {
            if (!has[i] && cnt[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};