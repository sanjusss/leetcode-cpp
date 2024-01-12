/*
 * @Author: sanjusss
 * @Date: 2024-01-12 09:03:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-01-12 09:08:49
 * @FilePath: \2000\2000\2080\2085.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> cnt1;
        for (auto& s : words1) {
            cnt1[s] += 1;
        }

        unordered_map<string, int> cnt2;
        for (auto& s : words2) {
            cnt2[s] += 1;
        }

        int ans = 0;
        for (auto& [s, c] : cnt1) {
            if (c == 1 && cnt2[s] == 1) {
                ++ans;
            }
        }

        return ans;
    }
};