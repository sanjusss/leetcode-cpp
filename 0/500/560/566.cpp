/*
 * @Author: sanjusss
 * @Date: 2021-02-17 09:29:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-17 09:34:42
 * @FilePath: \0\500\560\566.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }

        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                ans[i][j] = nums[(i * c + j) / n][(i * c + j) % n];
            }
        }

        return ans;
    }
};

TEST(&Solution::matrixReshape)