/*
 * @Author: sanjusss
 * @Date: 2022-05-09 08:44:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-09 08:51:53
 * @FilePath: \0\400\440\442.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i + 1 && nums[i] != 0) {
                if (nums[nums[i] - 1] == nums[i]) {
                    ans.push_back(nums[i]);
                    nums[i] = 0;
                    break;
                }
                else {
                    swap(nums[i], nums[nums[i] - 1]);
                }
            }
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::findDuplicates)