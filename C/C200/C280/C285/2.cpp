/*
 * @Author: sanjusss
 * @Date: 2022-03-20 10:22:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-20 10:44:12
 * @FilePath: \C\C200\C280\C285\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0;
        while (left < n && directions[left] == 'L') {
            ++left;
        }

        int right = n - 1;
        while (right >= 0 && directions[right] == 'R') {
            --right;
        }

        int ans = 0;
        for (int i = left; i <= right; ++i) {
            if (directions[i] != 'S') {
                ++ans;
            }
        }

        return ans;
    }
};