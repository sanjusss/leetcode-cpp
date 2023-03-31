/*
 * @Author: sanjusss
 * @Date: 2023-03-31 08:29:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-31 08:34:20
 * @FilePath: \2000\2300\2360\2367.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        int j = 0; 
        int k = 0;
        while (i < n) {
            while (j < n && nums[j] - nums[i] < diff) {
                ++j;
            }

            if (j == n) {
                break;
            }

            
            while (k < n && nums[k] - nums[j] < diff) {
                ++k;
            }

            if (k == n) {
                break;
            }

            if (nums[i] + diff == nums[j] && nums[j] + diff == nums[k]) {
                ++ans;
            }

            ++i;
        }

        return ans;
    }
};