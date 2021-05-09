/*
 * @Author: sanjusss
 * @Date: 2021-05-09 20:31:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-09 20:43:45
 * @FilePath: \1000\1400\1480\1482.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m * k) {
            return -1;
        }

        int left = 1;
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left < right) {
            int mid = (left + right) / 2;
            int mi = 0;
            int ki = 0;
            for (int i : bloomDay) {
                if (i <= mid) {
                    if (++ki == k) {
                        ki = 0;
                        ++mi;
                    }
                }
                else {
                    ki = 0;
                }
            }

            if (mi >= m) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

TEST(&Solution::minDays)