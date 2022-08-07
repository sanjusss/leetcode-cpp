/*
 * @Author: sanjusss
 * @Date: 2022-08-07 10:39:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-07 10:48:10
 * @FilePath: \C\C300\C300\C305\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vaild(n);
        for (int i = 0; i < n; ++i) {
            if (i >= 1 && nums[i] == nums[i - 1] && ((i - 2 < 0) || vaild[i - 2])) {
                vaild[i] = true;
            }
            else if (i >= 2 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2] && ((i - 3 < 0) || vaild[i - 3])) {
                vaild[i] = true;
            }
            else if (i >= 2 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1 &&
                     ((i - 3 < 0) || vaild[i - 3])) {
                vaild[i] = true;
            }
        }

        return vaild.back();
    }
};