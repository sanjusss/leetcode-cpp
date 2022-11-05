/*
 * @Author: sanjusss
 * @Date: 2022-11-05 08:58:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-05 10:00:11
 * @FilePath: \1000\1100\1100\1106.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        vector<int> rights(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            switch (expression[i]) {
                case ')':
                    s.push(i + 1);
                    break;

                case '(':
                    rights[i] = s.top();
                    s.pop();
                    break;

                case '!':
                case '&':
                case '|':
                    rights[i] = rights[i + 1];
                    break;

                default:
                    rights[i] = i + 1;
                    break;
            }
        }

        function<bool(int, int)> dfs = [&](int i, int end) -> bool {
            if (expression[i] == '!') {
                return !dfs(i + 2, end - 1);
            }
            else if (expression[i] == '&') {
                i += 2;
                end -= 1;
                while (i < end) {
                    if (!dfs(i, rights[i])) {
                        return false;
                    }

                    i = rights[i] + 1;
                }

                return true;
            }
            else if (expression[i] == '|') {
                i += 2;
                end -= 1;
                while (i < end) {
                    if (dfs(i, rights[i])) {
                        return true;
                    }

                    i = rights[i] + 1;
                }

                return false;
            }
            else {
                return expression[i] == 't';
            }
        };
        return dfs(0, n);
    }
};

TEST(&Solution::parseBoolExpr)