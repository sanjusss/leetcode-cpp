/*
 * @Author: sanjusss
 * @Date: 2021-10-22 10:12:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-22 10:15:11
 * @FilePath: \0\0\60\66_20211022.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int r = 1;
        for (auto i = digits.rbegin(); i != digits.rend(); ++i) {
            ans.push_back(*i + r);
            r = ans.back() / 10;
            ans.back() %= 10;
        }

        if (r > 0) {
            ans.push_back(r);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};