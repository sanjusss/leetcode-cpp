/*
 * @Author: sanjusss
 * @Date: 2022-03-01 08:30:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-01 08:48:17
 * @FilePath: \0\0\0\6_20220301.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        vector<string> rows(n);
        for (int i = 0; i < n; ++i) {
            int r;
            if (numRows >= 3) {
                r = i % (numRows * 2 - 2);
                if (r >= numRows) {
                    r = numRows * 2 - 2 - r;
                }
            }
            else {
                r = i % numRows;
            }

            rows[r].push_back(s[i]);
        }

        string ans;
        for (auto& i : rows) {
            ans += i;
        }

        return ans;
    }
};