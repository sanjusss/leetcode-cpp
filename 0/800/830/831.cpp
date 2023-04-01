/*
 * @Author: sanjusss
 * @Date: 2023-04-01 19:59:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-01 20:35:02
 * @FilePath: \0\800\830\831.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string maskPII(string s) {
        if (isalpha(s[0])) {
            string ans;
            ans.push_back(tolower(s[0]));
            ans += "*****"s;
            ans.push_back(tolower(s[0]));
            bool hasAt = false;
            for (char i : s) {
                if (i == '@') {
                    hasAt = true;
                    ans.push_back('@');
                }
                else if (hasAt) {
                    ans.push_back(tolower(i));
                }
                else {
                    ans.back() = tolower(i);
                }
            }

            return ans;
        }
        else {
            int n = s.size();
            string ans;
            for (int i = n - 1; i > 0; --i) {
                if (isdigit(s[i])) {
                    if (ans.size() < 4) {
                        ans.push_back(s[i]);
                    }
                    else {
                        ans.push_back('*');
                    }

                    if (ans.size() % 4 == 0) {
                        ans.push_back('-');
                    }
                }
            }

            if (isdigit(s[0])) {
                ans.push_back('*');
            }

            if (ans.back() == '-') {
                ans.pop_back();
            }

            if (ans.size() > 12) {
                ans.push_back('+');
            }

            reverse(ans.begin(), ans.end());
            return ans;
        }
    }
};