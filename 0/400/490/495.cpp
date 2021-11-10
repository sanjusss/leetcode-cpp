/*
 * @Author: sanjusss
 * @Date: 2021-11-10 14:21:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-10 14:25:06
 * @FilePath: \0\400\490\495.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int prev = -1;
        for (int i : timeSeries) {
            if (prev >= 0) {
                ans -= max(0, duration - (i - prev));
            }

            ans += duration;
            prev = i;
        }

        return ans;
    }
};