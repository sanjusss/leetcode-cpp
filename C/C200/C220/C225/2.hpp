/*
 * @Author: sanjusss
 * @Date: 2021-01-24 10:38:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-24 11:06:39
 * @FilePath: \C\C200\C220\C225\2.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int minCharacters(string a, string b) {
        array<int, 26> acnt = { 0 };
        array<int, 26> bcnt = { 0 };
        for (char i : a) {
            ++acnt[i - 'a'];
        }

        for (char i : b) {
            ++bcnt[i - 'a'];
        }

        int ans = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            int changeAsSame = 0;
            for (int j = 0; j < 26; ++j) {
                if (i != j) {
                    changeAsSame += acnt[j] + bcnt[j];
                }
            }

            int changeAsMore = 0;//b 都大于i
            int changeAsLE = 0;//b 都小于等于i
            for (int j = i + 1; j < 26; ++j) {
                changeAsMore += acnt[j];
                changeAsLE += bcnt[j];
            }

            for (int j = 0; j <= i; ++j) {
                changeAsMore += bcnt[j];
                changeAsLE += acnt[j];
            }

            if (i == 25) {
                ans = min(ans, changeAsSame);
            }
            else {
                ans = min({ ans, changeAsSame, changeAsMore, changeAsLE });
            }
        }

        return ans;
    }
};