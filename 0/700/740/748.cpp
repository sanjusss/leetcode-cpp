/*
 * @Author: sanjusss
 * @Date: 2021-12-10 08:25:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-10 08:31:01
 * @FilePath: \0\700\740\748.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cnt(26);
        for (char i : licensePlate) {
            if (isalpha(i)) {
                ++cnt[tolower(i) - 'a'];
            }
        }

        int ans = -1;
        int sum = accumulate(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < words.size(); ++i) {
            auto needs = cnt;
            int remain = sum;
            for (char j : words[i]) {
                if (--needs[j - 'a'] >= 0) {
                    --remain;
                }
            }

            if (remain == 0) {
                if (ans == -1 || words[i].size() < words[ans].size()) {
                    ans = i;
                }
            }
        }

        if (ans >= 0) {
            return words[ans];
        }
        else {
            return string();
        }
    }
};