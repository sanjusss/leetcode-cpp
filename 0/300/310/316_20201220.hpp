/*
 * @Author: sanjusss
 * @Date: 2020-12-20 11:43:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-20 12:04:21
 * @FilePath: \0\300\310\316_20201220.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        array<int, 26> cnt = { 0 };
        for (char i : s) {
            ++cnt[i - 'a'];
        }

        string ans;
        array<bool, 26> exist = { 0 };
        for (char i : s) {
            --cnt[i - 'a'];
            if (exist[i - 'a']) {
                continue;
            }

            while (!ans.empty() && ans.back() > i && cnt[ans.back() - 'a'] > 0) {
                exist[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(i);
            exist[i - 'a'] = true;
        }

        return ans;
    }
};