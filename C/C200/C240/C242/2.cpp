/*
 * @Author: sanjusss
 * @Date: 2021-05-23 10:34:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-23 10:47:17
 * @FilePath: \C\C200\C240\C242\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (ceil(hour) < dist.size()) {
            return -1;
        }

        int left = 1;
        int right = 1e7;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            double cost = 0;
            for (int i : dist) {
                cost = ceil(cost);
                cost += (double)i / (double)mid;
            }

            if (cost > hour) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};

TEST(&Solution::minSpeedOnTime)