/*
 * @Author: sanjusss
 * @Date: 2023-06-04 10:29:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-04 10:31:32
 * @FilePath: \C\C300\C340\C348\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> cs(s.begin(), s.end());
        return cs.size();
    }
};