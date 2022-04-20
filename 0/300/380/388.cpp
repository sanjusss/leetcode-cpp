/*
 * @Author: sanjusss
 * @Date: 2022-04-20 08:48:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-20 09:06:59
 * @FilePath: \0\300\380\388.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int lengthLongestPath(string input) {
        int ans = 0;
        int total = 0;
        int cur = 0;
        int tab = 0;
        bool hasDot = false;
        stack<int> dirs;
        int n = input.size();
        for (int i = 0; i <= n; ++i) {
            if (i == n || input[i] == '\n') {
                if (hasDot) {
                    ans = max(ans, cur + total);
                }
                else {
                    ++cur;
                    dirs.push(cur);
                    total += cur;
                }

                hasDot = false;
                cur = 0;
            }
            else if (input[i] == '\t') {
                ++tab;
            }
            else {
                if (cur == 0) {
                    while (dirs.size() > tab) {
                        total -= dirs.top();
                        dirs.pop();
                    }

                    tab = 0;
                }

                if (input[i] == '.') {
                    hasDot = true;
                }

                ++cur;
            }
        }

        return ans;
    }
};