/*
 * @Author: sanjusss
 * @Date: 2022-12-17 11:18:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-17 11:34:12
 * @FilePath: \0\0\20\28_20221217.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();
        vector<int> nexts(m);
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && needle[j] != needle[i]) {
                j = nexts[j - 1];
            }

            if (needle[j] == needle[i]) {
                ++j;
            }

            nexts[i] = j;
        }

        int n = haystack.size();
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = nexts[j - 1];
            }

            if (haystack[i] == needle[j]) {
                ++j;
            }
            
            if (j == m) {
                return i - m + 1;
            }
        }

        return -1;
    }
};