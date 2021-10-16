/*
 * @Author: sanjusss
 * @Date: 2021-10-16 10:21:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-16 11:31:06
 * @FilePath: \0\200\280\282.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string expr;
        int n = num.size();
        function<void(int, int64_t, int64_t)> dfs = [&](int i, int64_t cur, int64_t pre) {
            if (i == n) {
                if (cur == target) {
                    ans.push_back(expr);
                }

                return;
            }

            int signIndex = expr.size();
            if (i > 0) {
                expr.push_back('s');
            }

            int64_t val = 0;
            for (int j = i; j < n && (j == i || num[i] != '0'); ++j) {
                val = val * 10 + num[j] - '0';
                expr.push_back(num[j]);
                if (i == 0) {
                    dfs(j + 1, val, val);
                }
                else {
                    expr[signIndex] = '+';
                    dfs(j + 1, cur + val, val);
                    expr[signIndex] = '-';
                    dfs(j + 1, cur - val, -val);
                    expr[signIndex] = '*';
                    dfs(j + 1, cur - pre + pre * val, pre * val);
                }
            }

            expr.resize(signIndex);
        };

        dfs(0, 0 , 0);
        return ans;
    }
};

TEST_EQUIVALENT(&Solution::addOperators)