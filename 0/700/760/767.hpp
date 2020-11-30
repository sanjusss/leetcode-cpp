#pragma once
#include "leetcode.h"

class Solution {
public:
    string reorganizeString(string S) {
        array<int, 26> cnt = { 0 };
        for (char i : S) {
            ++cnt[i - 'a'];
        }

        int size = S.size();
        int maxCount = (size + 1) / 2;
        string ans(size, '0');
        int evenI = 0;
        int oddI = 1;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > maxCount) {
                return string();
            }

            if (evenI > 0 || cnt[i] != maxCount) {
                while (cnt[i]  > 0 && oddI < size) {
                    ans[oddI] = i + 'a';
                    --cnt[i] ;
                    oddI += 2;
                }
            }

            while (cnt[i] > 0) {
                ans[evenI] = i + 'a';
                --cnt[i];
                evenI += 2;
            }
        }

        return ans;
    }
};