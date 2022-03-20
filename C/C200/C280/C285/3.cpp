/*
 * @Author: sanjusss
 * @Date: 2022-03-20 10:22:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-20 10:56:05
 * @FilePath: \C\C200\C280\C285\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int score = 0;
        int smask = 0;
        for (int mask = (1 << 11) - 1; mask > 0; --mask) {
            int s = 0;
            int arrows = 0;
            for (int i = 0; i < 11; ++i) {
                if (mask & (1 << i)) {
                    s += i + 1;
                    arrows += aliceArrows[i + 1] + 1;
                }
            }

            if (s > score && arrows <= numArrows) {
                score = s;
                smask = mask;
            }
        }

        vector<int> ans(12);
        for (int i = 0; i < 11; ++i) {
            if (smask & (1 << i)) {
                ans[i + 1] = aliceArrows[i + 1] + 1;
                numArrows -= ans[i + 1];
            }
        }

        ans[0] = numArrows;
        return ans;
    }
};