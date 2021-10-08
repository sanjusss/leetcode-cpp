/*
 * @Author: sanjusss
 * @Date: 2021-10-08 08:48:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-08 08:59:55
 * @FilePath: \0\100\180\187.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string_view sv = s;
        unordered_map<string_view, int> cnt;
        for (int i = sv.size() - 10; i >= 0; --i) {
            ++cnt[sv.substr(i, 10)];
        }

        vector<string> ans;
        for (auto [v, c] : cnt) {
            if (c > 1) {
                ans.emplace_back(v);
            }
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::findRepeatedDnaSequences)