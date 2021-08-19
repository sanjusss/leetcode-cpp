/*
 * @Author: sanjusss
 * @Date: 2021-08-19 08:37:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-19 08:50:28
 * @FilePath: \0\300\340\345.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = { 'a', 'o', 'e', 'i', 'u', 'A', 'O', 'E', 'I', 'U' };
        int left = 0;
        int right = s.size() -1;
        while (left < right) {
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                ++left;
            }

            while (left < right && vowels.find(s[right]) == vowels.end()) {
                --right;
            }

            if (left < right) {
                swap(s[left], s[right]);
            }

            ++left;
            --right;
        }

        return s;
    }
};

TEST(&Solution::reverseVowels)