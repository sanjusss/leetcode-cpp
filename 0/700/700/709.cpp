/*
 * @Author: sanjusss
 * @Date: 2021-12-12 10:08:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-12 10:08:31
 * @FilePath: \0\700\700\709.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string toLowerCase(string s) {
        for (char& i : s) {
            i = tolower(i);
        }

        return s;
    }
};