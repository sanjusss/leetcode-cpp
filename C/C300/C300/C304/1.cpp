/*
 * @Author: sanjusss
 * @Date: 2022-07-31 10:24:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-31 10:31:12
 * @FilePath: \C\C300\C300\C304\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> vs(nums.begin(), nums.end());
        if (vs.count(0)) {
            return vs.size() - 1;
        }
        else {
            return vs.size();
        }
    }
};