/*
 * @Author: sanjusss
 * @Date: 2023-04-09 10:29:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-09 11:36:34
 * @FilePath: \C\C300\C340\C340\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums.front();
        while (left < right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            int prev = -1;
            for (int i : nums) {
                if (prev >= 0 && i - prev <= mid) {
                    ++cnt;
                    prev = -1;
                }
                else {
                    prev = i;
                }
            }

            if (cnt < p) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};

TEST(&Solution::minimizeMax)