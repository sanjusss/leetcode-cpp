/*
 * @Author: sanjusss
 * @Date: 2020-12-27 10:31:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-27 10:36:15
 * @FilePath: \C\C200\C220\C221\1.hpp
 */
#include "leetcode.h"

class Solution {
public:
    bool halvesAreAlike(string s) {
        static const unordered_set<char> cs = {'a','e','i','o','u','A','E','I','O','U'};
        int n = s.size();
        int half = n /2;
        int target = 0;
        for (int i = 0; i < half; ++i) {
            if (cs.find(s[i]) != cs.end()) {
                ++target;
            }
        }

        for (int i = half; i < n; ++i) {
            if (cs.find(s[i]) != cs.end()) {
                --target;
            }
        }

        return target == 0;
    }
};