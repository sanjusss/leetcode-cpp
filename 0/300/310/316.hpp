#pragma once
#include "leetcode.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        array<int, 26> cnt = { 0 };
        for (char i : s) {
            ++cnt[i - 'a'];
        }

        array<bool, 26> contains = { 0 };
        string temp;
        for (char i : s) {
            --cnt[i - 'a'];
            if (contains[i - 'a']) {
                continue;
            }

            contains[i - 'a'] = true;
            while (!temp.empty() && temp.back() > i && cnt[temp.back() - 'a'] > 0 ) {
                contains[temp.back() - 'a'] = false;
                temp.pop_back();
            }

            temp.push_back(i);
        }

        return temp;
    }
};