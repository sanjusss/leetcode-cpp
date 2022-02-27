/*
 * @Author: sanjusss
 * @Date: 2022-02-27 10:41:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-27 10:47:00
 * @FilePath: \C\C200\C280\C281\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int64_t left = 1;
        int64_t right = 1e14 + 1;
        while (left < right) {
            int64_t mid = (left + right) / 2;
            int64_t trips = 0;
            for (int t : time) {
                trips += mid / t;
            }

            if (trips >= totalTrips) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};