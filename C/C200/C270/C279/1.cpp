/*
 * @Author: sanjusss
 * @Date: 2022-02-06 10:28:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-06 10:34:59
 * @FilePath: \C\C200\C270\C279\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        multiset<int> odds;
        multiset<int> evens;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                odds.insert(nums[i]);
            }
            else {
                evens.insert(nums[i]);
            }
        }

        auto oddi = odds.rbegin();
        auto eveni = evens.begin();
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                nums[i] = *(oddi++);
            }
            else {
                nums[i] = *(eveni++);
            }
        }

        return nums;
    }
};