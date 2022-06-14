/*
 * @Author: sanjusss
 * @Date: 2022-06-14 08:47:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-14 09:15:39
 * @FilePath: \0\400\490\498_20220614.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        for (int sum = 0; sum <= m - 1 + n - 1; ++sum) {
            int maxi = min(sum, m - 1);
            int mini = sum - min(sum, n - 1);
            if (sum % 2 == 0) {
                for (int i = maxi; i >= mini; --i) {
                    ans.push_back(mat[i][sum - i]);
                }
            }
            else {
                for (int i = mini; i <= maxi; ++i) {
                    ans.push_back(mat[i][sum - i]);
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::findDiagonalOrder)