/*
 * @Author: sanjusss
 * @Date: 2022-06-19 10:29:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-19 10:36:31
 * @FilePath: \C\C200\C290\C298\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string greatestLetter(string s) {
        vector<int> l(26, -1);
        vector<int> u(26, -1);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                l[s[i] - 'a'] = i;
            }
            else {
                u[s[i] - 'A'] = i;
            }
        }

        for (int i = 25; i >= 0; --i) {
            if (l[i] >= 0 && u[i] >= 0) {
                return { char('A' + i) };
            }
        }

        return {};
    }
};