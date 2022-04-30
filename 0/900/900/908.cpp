/*
 * @Author: sanjusss
 * @Date: 2022-04-30 09:14:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-30 09:15:30
 * @FilePath: \0\900\900\908.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mine = *min_element(nums.begin(), nums.end());
        int maxe = *max_element(nums.begin(), nums.end());
        return max(0, maxe - mine - 2 * k);
    }
};