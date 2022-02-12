/*
 * @Author: sanjusss
 * @Date: 2022-02-12 12:14:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-12 12:15:43
 * @FilePath: \0\200\250\256.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> prev(3);
        vector<int> cur(3);
        for (auto& c : costs) {
            swap(cur, prev);
            cur[0] = c[0] + min(prev[1], prev[2]);
            cur[1] = c[1] + min(prev[0], prev[2]);
            cur[2] = c[2] + min(prev[0], prev[1]);
        }

        return *min_element(cur.begin(), cur.end());
    }
};