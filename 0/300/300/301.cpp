/*
 * @Author: sanjusss
 * @Date: 2021-10-27 09:31:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-27 11:13:50
 * @FilePath: \0\300\300\301.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;
        for (char i : s) {
            if (i == '(') {
                ++leftRemove;
            }
            else if (i == ')') {
                if (leftRemove > 0) {
                    --leftRemove;
                }
                else {
                    ++rightRemove;
                }
            }
        }

        int left = 0;
        int right = 0;
        unordered_set<string> ans;
        string cur;
        int n = s.size();
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                if (left == right && leftRemove == 0 && rightRemove == 0) {
                    ans.insert(cur);
                }

                return;
            }

            if (s[i] == '(') {
                if (leftRemove > 0) {
                    --leftRemove;
                    dfs(i + 1);
                    ++leftRemove;
                }

                ++left;
                cur.push_back(s[i]);
                dfs(i + 1);
                cur.pop_back();
                --left;
            }
            else if (s[i] == ')') {
                if (rightRemove > 0) {
                    --rightRemove;
                    dfs(i + 1);
                    ++rightRemove;
                }
                
                if (left > right) {
                    ++right;
                    cur.push_back(s[i]);
                    dfs(i + 1);
                    cur.pop_back();
                    --right;
                }
            }
            else {
                cur.push_back(s[i]);
                dfs(i + 1);
                cur.pop_back();
            }
        };
        dfs(0);
        return { ans.begin(), ans.end() };
    }
};

TEST_EQUIVALENT(&Solution::removeInvalidParentheses)