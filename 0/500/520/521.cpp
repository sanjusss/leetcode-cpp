/*
 * @Author: sanjusss
 * @Date: 2022-03-05 20:59:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-05 20:59:32
 * @FilePath: \0\500\520\521.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) {
            return -1;
        }
        else {
            return max(a.size(), b.size());
        }
    }
};