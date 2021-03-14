/*
 * @Author: sanjusss
 * @Date: 2021-03-14 10:41:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-14 10:43:27
 * @FilePath: \C\C200\C230\C232\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> cnt(n + 1);
        for (auto& e : edges) {
            if (++cnt[e[0]] == 2) {
                return e[0];
            }

            if (++cnt[e[1]] == 2) {
                return e[1];
            }
        }

        return 0;
    }
};