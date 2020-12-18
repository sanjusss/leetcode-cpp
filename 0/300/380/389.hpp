#pragma once
#include "leetcode.h"

class Solution {
public:
    char findTheDifference(string s, string t) {
        array<int, 26> cnt = { 0 };
        for (char i : s) {
            ++cnt[i - 'a'];
        }

        for (char i : t) {
            if (cnt[i - 'a'] == 0) {
                return i;
            }
            else {
                --cnt[i - 'a'];
            }
        }

        return 0;
    }
};