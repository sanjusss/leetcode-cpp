/*
 * @Author: sanjusss
 * @Date: 2022-05-17 08:38:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-17 08:44:32
 * @FilePath: \0\900\950\953.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        array<int, 26> o;
        for (int i = 0; i < 26; ++i) {
            o[order[i] - 'a'] = i;
        }

        auto cmp = [&o] (const string &a, const string &b) -> bool {
            int i = 0;
            while (i < a.size() && i < b.size()) {
                if (o[a[i] - 'a'] != o[b[i] - 'a']) {
                    return o[a[i] - 'a'] < o[b[i] - 'a'];
                }

                ++i;
            }

            return i >= a.size();
        };

        int n = words.size();
        for (int i = 1; i < n; ++i) {
            if (!cmp(words[i - 1], words[i])) {
                return false;
            }
        }

        return true;
    }
};