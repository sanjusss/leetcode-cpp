/*
 * @Author: sanjusss
 * @Date: 2022-01-09 10:26:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-09 10:52:47
 * @FilePath: \C\C200\C270\C275\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map<int, int> target;
        for (auto& s : targetWords) {
            int k = 0;
            for (char i : s) {
                k = k | (1 << (i - 'a'));
            }

            ++target[k];
        }

        int ans = 0;
        for (auto& s : startWords) {
            int k = 0;
            for (char i : s) {
                k = k | (1 << (i - 'a'));
            }

            for (int i = 0; i < 26; ++i) {
                int b = 1 << i;
                if (k & b) {
                    continue;
                }

                auto p = target.find(k | b);
                if (p == target.end()) {
                    continue;
                }

                ans += p->second;
                target.erase(p);
            }
        }

        return ans;
    }
};