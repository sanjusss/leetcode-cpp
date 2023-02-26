/*
 * @Author: sanjusss
 * @Date: 2023-02-19 10:29:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-26 10:46:11
 * @FilePath: \C\C300\C330\C334\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = n / 2;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            bool found = true;
            for (int i = 0, j = mid; i < mid; ++i) {
                while (j < n && nums[i] * 2 > nums[j]) {
                    ++j;
                }

                if (j == n) {
                    found = false;
                    break;
                }
                else {
                    ++j;
                }
            }

            if (found) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }

        return left * 2;
    }
};