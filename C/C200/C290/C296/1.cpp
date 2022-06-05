/*
 * @Author: sanjusss
 * @Date: 2022-06-05 10:27:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-05 10:32:04
 * @FilePath: \C\C200\C290\C296\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            for (int i = 0; i < nums.size() / 2; ++i) {
                if (i % 2 == 0) {
                    nums[i] = min(nums[i * 2], nums[i * 2 + 1]);
                }
                else {
                    nums[i] = max(nums[i * 2], nums[i * 2 + 1]);
                }
            }

            nums.resize(nums.size() / 2);
        }

        return nums.front();
    }
};