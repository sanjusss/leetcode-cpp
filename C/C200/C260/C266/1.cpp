/*
 * @Author: sanjusss
 * @Date: 2021-11-07 10:29:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-07 10:35:20
 * @FilePath: \C\C200\C260\C266\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countVowelSubstrings(string word) {
        static const unordered_set<char> vowels = { 'a', 'i', 'e', 'u', 'o' };
        int ans = 0;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            if (!vowels.count(word[i])) {
                continue;
            }

            unordered_set<char> cnt;
            cnt.insert(word[i]);
            for (int j = i + 1; j < n && vowels.count(word[j]); ++j) {
                cnt.insert(word[j]);
                if (cnt.size() == 5) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};