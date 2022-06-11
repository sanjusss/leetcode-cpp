/*
 * @Author: sanjusss
 * @Date: 2022-06-11 10:13:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-11 10:19:55
 * @FilePath: \0\900\920\926.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt = 0;
        for (char i : s) {
            if (i == '1') {
                ++cnt;
            }
        }

        int ans = cnt;
        int n = s.size();
        int prevChange = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                --cnt;
            }
            else {
                ++prevChange;
            }

            ans = min(ans, cnt + prevChange);
        }

        return ans;
    }
};

TEST(&Solution::minFlipsMonoIncr)