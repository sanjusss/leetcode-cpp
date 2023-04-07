/*
 * @Author: sanjusss
 * @Date: 2023-04-07 15:56:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-07 16:39:39
 * @FilePath: \1000\1000\1040\1040.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        if (stones.back() - stones.front() == n - 1) {
            return {{ 0, 0 }};
        }

        int ansMax = max(stones[n - 2] - stones[0], stones[n - 1] - stones[1]) - 1 - (n - 3);
        int ansMin = ansMax;
        int right = 0;
        int left = 0;
        while (right < n) {
            while (stones[right] - stones[left] >= n) {
                ++left;
            }

            if (n - (right - left + 1) == 1 && stones[right] - stones[left] + 1 == n - 1) {
                ansMin = min(ansMin, 2);
            }
            else {
                ansMin = min(ansMin, n - (right - left + 1));
            }

            ++right;
        }

        return {{ ansMin, ansMax }};
    }
};