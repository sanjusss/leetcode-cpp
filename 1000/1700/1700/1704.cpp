/*
 * @Author: sanjusss
 * @Date: 2022-11-11 08:38:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-11 08:46:02
 * @FilePath: \1000\1700\1700\1704.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool halvesAreAlike(string s) {
        static const unordered_set<char> cs = {
            'a','e','i','o','u','A','E','I','O','U'
        };
        
        int left = 0;
        int right = 0;
        int n = s.size();
        int half = n / 2;
        for (int i = 0; i < n; ++i) {
            if (cs.count(s[i])) {
                if (i < half) {
                    ++left;
                }
                else {
                    ++right;
                }
            }
        }

        return left == right;
    }
};