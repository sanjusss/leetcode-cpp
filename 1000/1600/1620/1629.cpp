/*
 * @Author: sanjusss
 * @Date: 2022-01-09 10:27:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-09 10:29:40
 * @FilePath: \1000\1600\1620\1629.cpp
 */
#include "leetcode.h"

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        int prev = 0;
        int slow = 0;
        char ans = 0;
        for (int i = 0; i < n; ++i) {
            int t = releaseTimes[i] - prev;
            prev = releaseTimes[i];
            if (t > slow || (t == slow && ans < keysPressed[i])) {
                ans = keysPressed[i];
                slow = t;
            }
        }

        return ans;
    }
};