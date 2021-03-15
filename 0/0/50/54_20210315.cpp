#include "leetcode.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        ans.reserve(m * n);
        int left = 0;
        int right = n - 1;
        int top = 0;
        int buttom = m - 1;
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