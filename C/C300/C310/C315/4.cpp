/*
 * @Author: sanjusss
 * @Date: 2022-10-16 10:45:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-16 11:16:32
 * @FilePath: \C\C300\C310\C315\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int64_t ans = 0;
        int64_t n = nums.size();
        
        int64_t minI = -1;
        int64_t maxI = -1;
        int64_t begin = 0;
        for (int64_t i = 0; i < n; ++i) {
            if (nums[i] > maxK || nums[i] < minK) {
                minI = -1;
                maxI = -1;
                begin = i + 1;
                continue;
            }

            if (nums[i] == maxK) {
                maxI = i;
            }

            if (nums[i] == minK) {
                minI = i;
            }

            int64_t end = min(maxI, minI);
            if (end == -1) {
                continue;
            }

            ans += end - begin + 1;
        }

        return ans;
    }
};

TEST(&Solution::countSubarrays)