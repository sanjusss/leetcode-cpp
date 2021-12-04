/*
 * @Author: sanjusss
 * @Date: 2021-12-04 13:08:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-04 13:08:27
 * @FilePath: \0\300\380\383.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> cnt;
        for (char i : magazine) {
            ++cnt[i];
        }

        for (char i : ransomNote) {
            if (--cnt[i] < 0) {
                return false;
            }
        }

        return true;
    }
};