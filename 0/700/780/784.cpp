/*
 * @Author: sanjusss
 * @Date: 2022-10-30 10:10:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-30 10:15:32
 * @FilePath: \0\700\780\784.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        ans.emplace_back();
        for (char i : s) {
            if (i >= '0' && i <= '9') {
                for (auto& j : ans) {
                    j.push_back(i);
                }

                continue;
            }

            char c = (i >= 'a' && i <= 'z') ? i - 'a' : i - 'A';
            int n = ans.size();
            for (int j = 0; j < n; ++j) {
                ans.push_back(ans[j]);
                ans[j].push_back(c + 'a');
                ans[j + n].push_back(c + 'A');
            }
        }

        return ans;
    }
};