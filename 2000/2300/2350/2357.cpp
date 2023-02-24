/*
 * @Author: sanjusss
 * @Date: 2023-02-24 08:29:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-24 08:30:18
 * @FilePath: \2000\2300\2350\2357.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> vs(nums.begin(), nums.end());
        vs.erase(0);
        return vs.size();
    }
};