/*
 * @Author: sanjusss
 * @Date: 2022-12-24 08:58:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-24 09:01:37
 * @FilePath: \1000\1700\1750\1754.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string_view a = word1;
        string_view b = word2;
        string ans;
        while (!a.empty() || !b.empty()) {
            if (a > b) {
                ans.push_back(a.front());
                a.remove_prefix(1);
            }
            else {
                ans.push_back(b.front());
                b.remove_prefix(1);
            }
        }

        return ans;
    }
};