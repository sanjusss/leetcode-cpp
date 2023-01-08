/*
 * @Author: sanjusss
 * @Date: 2023-01-08 10:14:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-08 10:14:16
 * @FilePath: \2000\2100\2180\2185.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (auto& s : words) {
            if (s.compare(0, pref.size(), pref) == 0) {
                ++ans;
            }
        }

        return ans;
    }
};