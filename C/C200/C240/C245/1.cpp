/*
 * @Author: sanjusss
 * @Date: 2021-06-13 10:25:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-13 10:32:33
 * @FilePath: \C\C200\C240\C245\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        array<int, 26> cnt = { 0 };
        for (auto& s : words) {
            for (char i : s) {
                ++cnt[i - 'a'];
            }
        }

        int n = words.size();
        for (int i : cnt) {
            if (i % n != 0) {
                return false;
            }
        }

        return true;
    }
};