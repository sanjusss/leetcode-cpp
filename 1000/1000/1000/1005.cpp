/*
 * @Author: sanjusss
 * @Date: 2021-12-04 12:47:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-04 13:03:45
 * @FilePath: \1000\1000\1000\1005.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                if (k > 0) {
                    if (i + 1 == n) {
                        if (k & 1) {
                            ans -= nums[i];
                        }
                        else {
                            ans += nums[i];
                        }
                    }
                    else if (nums[i + 1] <= 0) {
                        ans -= nums[i];
                        --k;
                    }
                    else if (k & 1) {
                        ans -= nums[i];
                        k = 0;
                    }
                    else if (-nums[i] > nums[i + 1]) {
                        ans -= nums[i];
                        k = 1;
                    }
                    else {
                        ans += nums[i];
                    }
                }
                else {
                    ans += nums[i];
                }
            }
            else if (nums[i] == 0) {
                k = 0;
            }
            else {
                if (k & 1) {
                    k = 0;
                    ans -= nums[i];
                }
                else {
                    ans += nums[i];
                }
            }
        }

        return ans;
    }
};