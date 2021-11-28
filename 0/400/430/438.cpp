/*
 * @Author: sanjusss
 * @Date: 2021-11-28 10:48:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-28 10:54:43
 * @FilePath: \0\400\430\438.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> target(26);
        for (char i : p) {
            ++target[i - 'a'];
        }

        int pn = p.size();
        int sn = s.size();
        vector<int> cur(26);
        vector<int> ans;
        for (int i = 0; i < sn; ++i) {
            ++cur[s[i] - 'a'];
            if (i - pn >= 0) {
                --cur[s[i - pn] - 'a'];
            }

            if (i - pn + 1 < 0) {
                continue;
            }

            bool success = true;
            for (int j = 0; j < 26; ++j) {
                if (cur[j] != target[j]) {
                    success = false;
                    break;
                }
            }

            if (success) {
                ans.push_back(i - pn + 1);
            }
        }

        return ans;
    }
};