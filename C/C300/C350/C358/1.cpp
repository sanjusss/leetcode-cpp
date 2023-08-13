/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-13 10:34:18
 * @FilePath: \C\C300\C350\C358\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = -1;
        vector<pair<int, int>> maxB(10, make_pair(INT_MIN, INT_MIN));
        for (int i : nums) {
            int b = 0;
            for (int j = i; j > 0; j /= 10) {
                b = max(b, j % 10);
            }

            auto &[f, s] = maxB[b];
            if (i > f) {
                s = f;
                f = i;
            }
            else if (i > s) {
                s = i;
            }

            ans = max(ans, f + s);
        }

        return ans;
    }
};