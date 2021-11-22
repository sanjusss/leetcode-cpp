/*
 * @Author: sanjusss
 * @Date: 2021-11-07 10:37:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-07 10:43:49
 * @FilePath: \C\C200\C260\C266\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long countVowels(string word) {
        static const unordered_set<char> vowels = { 'a', 'i', 'e', 'u', 'o' };
        long long ans = 0;
        long long prev = 0;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            ans += prev;
            if (vowels.count(word[i])) {
                ans += i + 1;
                prev += i + 1;
            }
        }

        return ans;
    }
};