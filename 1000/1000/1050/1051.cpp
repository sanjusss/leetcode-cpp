/*
 * @Author: sanjusss
 * @Date: 2022-06-13 08:27:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-13 08:28:47
 * @FilePath: \1000\1000\1050\1051.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        int n = expected.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (expected[i] != heights[i]) {
                ++ans;
            }
        }

        return ans;
    }
};