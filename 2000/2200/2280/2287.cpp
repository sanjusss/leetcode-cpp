/*
 * @Author: sanjusss
 * @Date: 2023-01-13 08:29:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-13 08:31:53
 * @FilePath: \2000\2200\2280\2287.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> scnt(26);
        for (char i : s) {
            ++scnt[i - 'a'];
        }

        vector<int> dcnt(26);
        for (char i : target) {
            ++dcnt[i - 'a'];
        }

        int ans = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (dcnt[i] > 0) {
                ans = min(ans, scnt[i] / dcnt[i]);
            } 
        }

        return ans;
    }
};