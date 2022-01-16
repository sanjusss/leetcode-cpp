/*
 * @Author: sanjusss
 * @Date: 2022-01-16 10:27:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-16 10:32:35
 * @FilePath: \C\C200\C270\C276\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string temp;
        for (char i : s) {
            temp.push_back(i);
            if (temp.size() == k) {
                ans.push_back(temp);
                temp.clear();
            }
        }

        if (!temp.empty()) {
            while (temp.size() != k) {
                temp.push_back(fill);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};