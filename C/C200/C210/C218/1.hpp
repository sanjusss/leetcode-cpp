/*
 * @Author: sanjusss
 * @Date: 2020-12-06 10:35:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-06 11:08:34
 * @FilePath: \C\C200\C210\C218\1.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    string interpret(string command) {
        string ans;
        char prev = 0;
        for (char i : command) {
            if (i == ')') {
                if (prev == '(') {
                    ans.push_back('o');
                }
            }
            else if (i != '(') {
                ans.push_back(i);
            }

            prev = i;
        }

        return ans;
    }
};