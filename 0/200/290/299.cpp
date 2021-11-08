/*
 * @Author: sanjusss
 * @Date: 2021-11-08 18:28:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-08 19:51:26
 * @FilePath: \0\200\290\299.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> cnt;
        for (char i : secret) {
            ++cnt[i];
        }

        int a = 0;
        int b = 0;
        int n = guess.size();
        for (int i = 0; i < n; ++i) {
            if (guess[i] == secret[i]) {
                ++a;
                --cnt[guess[i]];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (guess[i] != secret[i] && cnt[guess[i]] > 0) {
                ++b;
                --cnt[guess[i]];
            }
        }

        return to_string(a) + "A"s + to_string(b) + "B";
    }
};
