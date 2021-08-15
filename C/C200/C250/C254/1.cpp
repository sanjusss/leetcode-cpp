/*
 * @Author: sanjusss
 * @Date: 2021-08-15 10:30:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-15 10:32:36
 * @FilePath: \C\C200\C250\C254\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (string& p : patterns) {
            if (word.find(p) != string::npos) {
                ++ans;
            }
        }

        return ans;
    }
};