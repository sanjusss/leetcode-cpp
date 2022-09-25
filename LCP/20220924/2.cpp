/*
 * @Author: sanjusss
 * @Date: 2022-09-24 15:33:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-24 15:36:21
 * @FilePath: \LCP\20220924\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int transportationHub(vector<vector<int>>& path) {
        unordered_map<int, int> outs;
        unordered_map<int, int> ins;
        unordered_set<int> all;
        for (auto &p : path) {
            ++outs[p[0]];
            ++ins[p[1]];
            all.insert(p[0]);
            all.insert(p[1]);
        }

        int cnt = all.size();
        for (auto [i, c] : ins) {
            if (c == cnt - 1 && !outs.count(i)) {
                return i;
            }
        }

        return -1;
    }
};