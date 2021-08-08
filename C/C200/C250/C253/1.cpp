/*
 * @Author: sanjusss
 * @Date: 2021-08-08 10:29:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-08 10:33:21
 * @FilePath: \C\C200\C250\C253\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string temp;
        for (string& i : words) {
            temp += i;
            if (temp == s) {
                return true;
            }
            else if (temp.size() > s.size()) {
                break;
            }
        }

        return false;
    }
};