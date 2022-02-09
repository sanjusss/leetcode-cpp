/*
 * @Author: sanjusss
 * @Date: 2022-02-09 15:54:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-09 16:54:13
 * @FilePath: \0\200\240\241.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> ops;
        int cur = 0;
        for (char i : expression) {
            if (isdigit(i)) {
                cur = cur * 10 + i - '0';
            }
            else {
                nums.push_back(cur);
                ops.push_back(i);
                cur = 0;
            }
        }

        nums.push_back(cur);

        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i].push_back(nums[i]);
            for (int j = i + 1; j < n; ++j) {
                for (int k = i; k < j; ++k) {
                    calc(dp[i][k], dp[k + 1][j], ops[k], dp[i][j]);
                }
            }
        }

        return dp[0][n - 1];
    }

private:
    static void calc(vector<int>& a, vector<int>& b, char op, vector<int>& ans) {
        for (int i : a) {
            for (int j : b) {
                if (op == '+') {
                    ans.push_back(i + j);
                }
                else if (op == '-') {
                    ans.push_back(i - j);
                }
                else {
                    ans.push_back(i * j);
                }
            }
        }
    }
};

TEST_EQUIVALENT(&Solution::diffWaysToCompute)