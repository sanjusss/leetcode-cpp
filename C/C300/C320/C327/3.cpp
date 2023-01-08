/*
 * @Author: sanjusss
 * @Date: 2023-01-08 10:25:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-08 10:40:59
 * @FilePath: \C\C300\C320\C327\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> cnt1(26);
        for (char c : word1) {
            ++cnt1[c - 'a'];
        }

        vector<int> cnt2(26);
        for (char c : word2) {
            ++cnt2[c - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] == 0) {
                continue;
            }

            for (int j = 0; j < 26; ++j) {
                if (cnt2[j] == 0) {
                    continue;
                }

                --cnt1[i];
                ++cnt1[j];
                --cnt2[j];
                ++cnt2[i];

                int diff1 = 0;
                for (int k = 0; k < 26; ++k) {
                    if (cnt1[k] > 0) {
                        ++diff1;
                    }
                }

                int diff2 = 0;
                for (int k = 0; k < 26; ++k) {
                    if (cnt2[k] > 0) {
                        ++diff2;
                    }
                }

                if (diff1 == diff2) {
                    return true;
                }

                ++cnt1[i];
                --cnt1[j];
                ++cnt2[j];
                --cnt2[i];
            }
        }

        return false;
    }
};