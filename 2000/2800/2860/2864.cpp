/*
 * @Author: sanjusss
 * @Date: 2024-03-13 08:44:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-03-13 08:44:40
 * @FilePath: \2000\2800\2860\2864.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        vector<int> cnt(2);
        for (char i : s) {
            cnt[i - '0'] += 1;
        }

        string ans;

        for (int i = 1; i < cnt[1]; ++i) {
            ans.push_back('1');
        }

        for (int i = 0; i < cnt[0]; ++i) {
            ans.push_back('0');
        }

        ans.push_back('1');
        return ans;
    }
};