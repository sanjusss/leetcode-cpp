/*
 * @Author: sanjusss
 * @Date: 2021-08-01 10:28:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-01 10:37:32
 * @FilePath: \C\C200\C250\C252\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int64_t sum = accumulate(milestones.begin(), milestones.end(), (int64_t)0);
        int64_t bigger = *max_element(milestones.begin(), milestones.end());
        if (bigger <= sum / 2) {
            return sum;
        }
        else {
            return (sum - bigger) * 2 + 1;
        }
    }
};