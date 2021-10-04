/*
 * @Author: sanjusss
 * @Date: 2021-10-04 09:59:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-04 10:18:31
 * @FilePath: \0\400\480\482.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cnt = 0;
        for (char i : s) {
            if (i != '-') {
                ++cnt;
            }
        }

        string ans;
        int r = cnt % k;
        for (int i = 0; i < s.size() && cnt > 0;) {
            if (!ans.empty()) {
                ans.push_back('-');
            }

            for (int j = r > 0 ? r : k; j > 0; --j) {
                while (s[i] == '-') {
                    ++i;
                }

                ans.push_back(toupper(s[i++]));
                --cnt;
            }

            r = 0;
        }

        return ans;
    }
};

TEST(&Solution::licenseKeyFormatting)