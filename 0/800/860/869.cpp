/*
 * @Author: sanjusss
 * @Date: 2021-10-28 08:50:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-28 09:00:50
 * @FilePath: \0\800\860\869.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        array<int, 10> cnt = { 0 };
        int len = 0;
        for (int i = n; i > 0; i /= 10) {
            ++len;
            ++cnt[i % 10];
        }

        for (int64_t i = 1;; i *= 2) {
            array<int, 10> cnti = { 0 };
            int leni = 0;
            for (int j = i; j > 0; j /= 10) {
                ++leni;
                ++cnti[j % 10];
            }

            if (leni < len) {
                continue;
            }
            else if (leni > len) {
                break;
            }

            bool success = true;
            for (int j = 0; j < 10; ++j) {
                if (cnt[j] != cnti[j]) {
                    success = false;
                    break;
                }
            }

            if (success) {
                return true;
            }
        }

        return false;
    }
};

TEST(&Solution::reorderedPowerOf2)