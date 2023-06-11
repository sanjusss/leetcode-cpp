/*
 * @Author: sanjusss
 * @Date: 2023-06-04 10:29:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-11 10:32:16
 * @FilePath: \C\C300\C340\C349\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        set<int> vs(nums.begin(), nums.end());
        if (vs.size() > 2) {
            return *(next(vs.begin()));
        }
        else {
            return -1;
        }
    }
};