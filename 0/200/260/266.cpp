/*
 * @Author: sanjusss
 * @Date: 2022-06-22 08:36:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-22 08:37:57
 * @FilePath: \0\200\260\266.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> cnt;
        for (char i : s) {
            ++cnt[i];
        }

        bool hasOdd = false;
        for (auto [_, c] : cnt) {
            if (c % 2 == 1) {
                if (hasOdd) {
                    return false;
                }
                else {
                    hasOdd = true;
                }
            }
        }

        return true;
    }
};