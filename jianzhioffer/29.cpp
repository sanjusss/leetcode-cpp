/*
 * @Author: sanjusss
 * @Date: 2021-08-30 08:45:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-30 09:04:22
 * @FilePath: \jianzhioffer\29.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top = 0;
        int buttom = matrix.size() - 1;
        if (buttom < top) {
            return ans;
        }

        int left = 0;
        int right = matrix[0].size() - 1;
        if (right < left) {
            return ans;
        }

        while (left <= right && top <= buttom) {
            for (int i = left; i <= right; ++i) {
                ans.push_back(matrix[top][i]);
            }

            for (int i = top + 1; i <= buttom; ++i) {
                ans.push_back(matrix[i][right]);
            }

            if (buttom != top) {
                for (int i = right - 1; i >= left; --i) {
                    ans.push_back(matrix[buttom][i]);
                }
            }
            
            if (left != right) {
                for (int i = buttom - 1; i > top; --i) {
                    ans.push_back(matrix[i][left]);
                }
            }

            ++left;
            --right;
            ++top;
            --buttom;
        }

        return ans;
    }
};

TEST(&Solution::spiralOrder)