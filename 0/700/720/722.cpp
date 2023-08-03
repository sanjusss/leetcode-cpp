/*
 * @Author: sanjusss
 * @Date: 2023-08-03 08:15:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-03 08:27:29
 * @FilePath: \0\700\720\722.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        ans.emplace_back();
        bool part = false;
        for (auto& s : source) {
            bool line = false;
            char pre = 0;
            for (char i : s) {
                if (part) {
                    if (pre == '*' && i == '/') {
                        pre = 0;
                        part = false;
                        continue;
                    }

                    pre = i;
                }
                else if (pre == '/') {
                    if (i == '/') {
                        line = true;
                        ans.back().pop_back();
                        break;
                    }
                    else if (i == '*') {
                        part = true;
                        pre = 0;
                        ans.back().pop_back();
                    }
                    else {
                        ans.back().push_back(i);
                        pre = i;
                    }
                }
                else {
                    ans.back().push_back(i);
                    pre = i;
                }
            }

            if (!part && ans.back().empty() == false) {
                ans.emplace_back();
            }
        }

        if (ans.back().empty()) {
            ans.pop_back();
        }

        return ans;
    }
};