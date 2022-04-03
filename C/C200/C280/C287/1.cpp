/*
 * @Author: sanjusss
 * @Date: 2022-04-03 10:19:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-03 10:33:40
 * @FilePath: \C\C200\C280\C287\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int convertTime(string current, string correct) {
        int diff = minutes(correct) - minutes(current);
        int ans = 0;
        ans += diff / 60;
        diff %= 60;
        ans += diff / 15;
        diff %= 15;
        ans += diff / 5;
        diff %= 5;
        ans += diff;
        return ans;
    }

private:
    int minutes(const string& s) {
        int h = s[0] * 10 + s[1];
        int m = s[3] * 10 + s[4];
        return h * 60 + m;
    }
};