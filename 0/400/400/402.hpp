/*
 * @Author: sanjusss
 * @Date: 2020-11-15 15:22:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-15 15:34:24
 * @FilePath: \0\400\400\402.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for (char i : num) {
            while (k > 0 && !ans.empty() && ans.back() > i) {
                ans.pop_back();
                --k;
            }

            ans.push_back(i);
        }

        while (k > 0) {
            ans.pop_back();
            --k;
        }

        for (int i = 0; i < ans.size(); ++i) {
            if (ans[i] != '0') {
                if (i == 0) {
                    return ans;
                }
                else {
                    return ans.substr(i);
                }
            }
        }

        return "0";
    }
};