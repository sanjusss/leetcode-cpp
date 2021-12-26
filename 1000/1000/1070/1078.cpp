/*
 * @Author: sanjusss
 * @Date: 2021-12-26 10:17:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-26 10:20:22
 * @FilePath: \1000\1000\1070\1078.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        int n = text.size();
        string cur;
        bool has1 = false;
        bool has2 = false;
        for (int i = 0; i <= n; ++i) {
            if (i == n || text[i] == ' ') {
                if (has2) {
                    ans.push_back(cur);
                }

                has2 = has1 && cur == second;
                has1 = cur == first;
                cur.clear();
            }
            else {
                cur.push_back(text[i]);
            }
        }

        return ans;
    }
};