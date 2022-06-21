/*
 * @Author: sanjusss
 * @Date: 2022-06-21 08:11:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-21 08:11:15
 * @FilePath: \1000\1100\1100\1108.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (char i : address) {
            if (i == '.') {
                ans += "[.]";
            }
            else {
                ans += i;
            }
        }

        return ans;
    }
};