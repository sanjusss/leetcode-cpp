/*
 * @Author: sanjusss
 * @Date: 2022-11-08 08:39:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-08 08:41:42
 * @FilePath: \1000\1600\1680\1684.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> all(26);
        for (char c : allowed) {
            all[c - 'a'] = true;
        }

        int ans = 0;
        for (auto& w : words) {
            bool success = true;
            for (char c : w) {
                if (!all[c - 'a']) {
                    success = false;
                    break;
                }
            }

            if (success) {
                ++ans;
            }
        }

        return ans;
    }
};