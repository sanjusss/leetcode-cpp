/*
 * @Author: sanjusss
 * @Date: 2023-10-15 10:38:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-05 10:35:46
 * @FilePath: \C\C300\C370\C370\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> ins(n);
        for (auto& e : edges) {
            ++ins[e[1]];
        }

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (ins[i] == 0) {
                if (ans < 0) {
                    ans = i;
                }
                else {
                    return -1;
                }
            }
        }

        return ans;
    }
};