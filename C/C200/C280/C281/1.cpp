/*
 * @Author: sanjusss
 * @Date: 2022-02-27 10:36:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-27 10:38:36
 * @FilePath: \C\C200\C280\C281\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        size_t size = pref.size();
        for (auto& s : words) {
            if (s.size() >= size && equal(s.begin(), s.begin() + size, pref.begin(), pref.end())) {
                ++ans;
            }
        }

        return ans;
    }
};