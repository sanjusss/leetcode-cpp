/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-09 11:05:07
 * @FilePath: \C\C300\C350\C353\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> changes(n + 1);
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            diff += changes[i];
            if (nums[i] < diff) {
                return false;
            }
            else if (nums[i] > diff) {
                if (i + k > n) {
                    return false;
                }

                changes[i + k] -= nums[i] - diff;
                diff = nums[i];
            }
        }

        return true;
    }
};

TEST(&Solution::checkArray)