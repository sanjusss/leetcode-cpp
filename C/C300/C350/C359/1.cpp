/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-20 10:31:13
 * @FilePath: \C\C300\C350\C359\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string t;
        for (auto& w : words) {
            t.push_back(w.front());
        }

        return t == s;
    }
};