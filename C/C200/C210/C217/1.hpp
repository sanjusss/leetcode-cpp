/*
 * @Author: sanjusss
 * @Date: 2020-11-29 10:32:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-29 10:34:23
 * @FilePath: \C\C200\C210\C217\1.hpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto& i : accounts) {
            ans = max(ans, accumulate(i.begin(), i.end(), 0));
        }

        return ans;
    }
};