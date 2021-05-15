/*
 * @Author: sanjusss
 * @Date: 2021-05-15 11:32:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-15 11:39:41
 * @FilePath: \0\0\10\13_20210515.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int romanToInt(string s) {
        static const unordered_map<char, int> dic = {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 },
        };
        int prev = INT_MAX;
        int ans = 0;
        for (char i : s) {
            int cur = dic.at(i);
            ans += cur;
            if (prev < cur) {
                ans -= 2 * prev;
            }

            prev = cur;
        }

        return ans;
    }
};

TEST(&Solution::romanToInt)