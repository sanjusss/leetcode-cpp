/*
 * @Author: sanjusss
 * @Date: 2021-11-22 09:12:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-22 09:44:23
 * @FilePath: \0\300\380\384_20211122.cpp
 */
#include "leetcode.h"

class Solution {
public:
    Solution(vector<int>& nums) : nums(nums) {
        srand(time(nullptr));
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        auto ans = nums;
        int n = ans.size();
        for (int i = n; i > 0; --i) {
            swap(nums[i - 1], nums[rand() % i]);
        }

        return ans;
    }

private:
    vector<int> nums;
};