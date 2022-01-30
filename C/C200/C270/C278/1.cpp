/*
 * @Author: sanjusss
 * @Date: 2022-01-30 10:28:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-30 10:31:32
 * @FilePath: \C\C200\C270\C278\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(original)) {
            original *= 2;
        }

        return original;
    }
};