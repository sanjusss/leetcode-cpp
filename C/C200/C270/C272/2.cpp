/*
 * @Author: sanjusss
 * @Date: 2021-12-19 10:14:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-19 10:38:33
 * @FilePath: \C\C200\C270\C272\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();
        int l = m + n;
        string ans(l, ' ');
        int cur = l - 1;
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[cur--] = s[i];
            if (j >= 0 && i == spaces[j]) {
                --cur;
                --j;
            }
        }

        return ans;
    }
};