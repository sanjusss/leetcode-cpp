/*
 * @Author: sanjusss
 * @Date: 2022-11-13 08:19:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-13 08:22:15
 * @FilePath: \0\700\790\791.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> cnt(26);
        for (char i : s) {
            ++cnt[i - 'a'];
        }

        string ans;
        for (char i : order) {
            for (int& j = cnt[i - 'a']; j > 0; --j) {
                ans.push_back(i);
            }
        }

        for (int i = 0; i < 26; ++i) {
            for (int& j = cnt[i]; j > 0; --j) {
                ans.push_back(i + 'a');
            }
        }

        return ans;
    }
};