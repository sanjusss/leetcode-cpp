/*
 * @Author: sanjusss
 * @Date: 2022-07-15 10:02:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-15 10:08:12
 * @FilePath: \0\300\360\360.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
//         for (int& i : nums) {
//             i = a * i * i + b * i + c;
//         }

//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0;
        int right = n - 1;
        if (a >= 0) {
            int i = n - 1;
            while (left <= right) {
                int l = a * nums[left] * nums[left] + b * nums[left] + c;
                int r = a * nums[right] * nums[right] + b * nums[right] + c;
                if (l >= r) {
                    ans[i--] = l;
                    ++left;
                }
                else {
                    ans[i--] = r;
                    --right;
                }
            }
        }
        else {
            int i = 0;
            while (left <= right) {
                int l = a * nums[left] * nums[left] + b * nums[left] + c;
                int r = a * nums[right] * nums[right] + b * nums[right] + c;
                if (l <= r) {
                    ans[i++] = l;
                    ++left;
                }
                else {
                    ans[i++] = r;
                    --right;
                }
            }
        }

        return ans;
    }
};