/*
 * @Author: sanjusss
 * @Date: 2022-12-17 11:35:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-17 11:35:27
 * @FilePath: \解题模板\kmp.h
 */
#include "leetcode.h"

int strStr(const string& text, const string& pattern) {
    int m = pattern.size();
    vector<int> nexts(m);
    for (int i = 1, j = 0; i < m; ++i) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = nexts[j - 1];
        }

        if (pattern[j] == pattern[i]) {
            ++j;
        }

        nexts[i] = j;
    }

    int n = text.size();
    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = nexts[j - 1];
        }

        if (text[i] == pattern[j]) {
            ++j;
        }

        if (j == m) {
            return i - m + 1;
        }
    }

    return -1;
}