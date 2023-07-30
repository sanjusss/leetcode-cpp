/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-30 10:32:17
 * @FilePath: \C\C300\C350\C356\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        for (int i : hours) {
            if (i >= target) {
                ++ans;
            }
        }

        return ans;
    }
};