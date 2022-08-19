/*
 * @Author: sanjusss
 * @Date: 2022-08-19 08:30:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-19 08:32:26
 * @FilePath: \1000\1400\1450\1450.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        vector<int> vs(1002);
        for (int i : startTime) {
            ++vs[i];
        }

        for (int i : endTime) {
            --vs[i + 1];
        }

        for (int i = 1; i <= queryTime; ++i) {
            vs[i] += vs[i - 1];
        }

        return vs[queryTime];
    }
};