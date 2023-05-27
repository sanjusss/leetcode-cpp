/*
 * @Author: sanjusss
 * @Date: 2023-05-21 10:27:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-21 10:32:34
 * @FilePath: \C\C300\C340\C346\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minLength(string s) {
        string ans;
        for (char i : s) {
            if (i == 'B' && !ans.empty() && ans.back() == 'A') {
                ans.pop_back();
            }
            else if (i == 'D' && !ans.empty() && ans.back() == 'C') {
                ans.pop_back();
            }
            else {
                ans.push_back(i);
            }
        }

        return ans.size();
    }
};