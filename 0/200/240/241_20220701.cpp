/*
 * @Author: sanjusss
 * @Date: 2022-07-01 08:13:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-01 08:58:56
 * @FilePath: \0\200\240\241_20220701.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> ops;
        for (char i : expression) {
            if (i >= '0' && i <= '9') {
                if (nums.empty()) {
                    nums.push_back(0);
                }

                nums.back() = nums.back() * 10 + i - '0';
            }
            else {
                ops.push_back(i);
                nums.push_back(0);
            }
        }

        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i].push_back(nums[i]);
            for (int j = i + 1; j < n; ++j) {
                for (int o = i; o < j; ++o) {
                    char op = ops[o];
                    for (int l : dp[i][o]) {
                        for (int m : dp[o + 1][j]) {
                            if (op == '+') {
                                dp[i][j].push_back(l + m);
                            }
                            else if (op == '-') {
                                dp[i][j].push_back(l - m);
                            }
                            else {
                                dp[i][j].push_back(l * m);
                            }
                        }
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};