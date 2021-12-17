/*
 * @Author: sanjusss
 * @Date: 2021-12-12 10:26:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-12 10:58:41
 * @FilePath: \C\C200\C270\C271\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int a = capacityA;
        int b = capacityB;
        int ans = 0;
        int mid = n / 2;
        int bbegin = n - 1;
        for (int i = 0; i < mid; ++i) {
            if (a < plants[i]) {
                a = capacityA;
                ++ans;
            }

            a -= plants[i];

            if (b < plants[bbegin - i]) {
                b = capacityB;
                ++ans;
            }

            b -= plants[bbegin - i];
        }

        if (n & 1) {
            if (max(a, b) < plants[mid]) {
                ++ans;
            }
        }

        return ans;
    }
};

TEST(&Solution::minimumRefill)