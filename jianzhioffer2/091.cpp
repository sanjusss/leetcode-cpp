/*
 * @Author: sanjusss
 * @Date: 2022-06-25 11:09:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-25 11:12:06
 * @FilePath: \jianzhioffer2\091.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> cur(3);
        vector<int> pre(3);
        for (auto& c : costs) {
            swap(cur, pre);
            cur[0] = c[0] + min(pre[1], pre[2]);
            cur[1] = c[1] + min(pre[0], pre[2]);
            cur[2] = c[2] + min(pre[0], pre[1]);
        }

        return *min_element(cur.begin(), cur.end());
    }
};