/*
 * @Author: sanjusss
 * @Date: 2021-09-04 15:40:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-04 15:50:12
 * @FilePath: \jianzhioffer\51.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        vector<int> temp(nums.size());
        function<void(int, int)> dfs = [&](int left, int right) {
            if (left >= right) {
                return;
            }

            int mid = (left + right) / 2;
            dfs(left, mid);
            dfs(mid + 1, right);
            int l = left;
            int r = mid + 1;
            for (int i = left; i <= right; ++i) {
                if (l > mid) {
                    temp[i] = nums[r++];
                }
                else if (r > right) {
                    temp[i] = nums[l++];
                }
                else if (nums[l] > nums[r]) {
                    temp[i] = nums[l++];
                    ans += right - r + 1;
                }
                else {
                    temp[i] = nums[r++];
                }
            }

            copy(temp.begin() + left, temp.begin() + right + 1, nums.begin() + left);
        };
        dfs(0, nums.size() - 1);
        return ans;
    }
};

TEST(&Solution::reversePairs)