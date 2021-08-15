/*
 * @Author: sanjusss
 * @Date: 2021-08-15 16:25:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-15 16:34:12
 * @FilePath: \jianzhioffer\48.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(CHAR_MAX + 1, -1);
        int n = s.size();
        bool find = false;
        int ans = 0;
        int start = -1;
        for (int i = 0; i < n; ++i) {
            if (pos[s[i]] >= 0) {
                find = true;
                start = max(pos[s[i]], start);
            }

            ans = max(i - start, ans);
            pos[s[i]] = i;
        }

        if (find) {
            return ans;
        }
        else {
            return n;
        }
    }
};