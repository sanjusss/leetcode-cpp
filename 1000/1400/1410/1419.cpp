/*
 * @Author: sanjusss
 * @Date: 2023-05-06 08:49:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-06 08:58:52
 * @FilePath: \1000\1400\1410\1419.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> trans = {
            { 'c', 0 }, { 'r', 1 }, { 'o', 2 }, { 'a', 3 }, { 'k', 4 },
        };

        vector<int> cnt(5);
        for (char c : croakOfFrogs) {
            int i = trans[c];
            if (i != 0) {
                if (--cnt[i - 1] >= 0) {
                    ++cnt[i];
                }
                else {
                    return -1;
                }
            }
            else {
                if (cnt[4] > 0) {
                    --cnt[4];
                }

                ++cnt[0];
            }
        }

        for (int i = 0; i < 4; ++i) {
            if (cnt[i] != 0) {
                return -1;
            }
        }

        return cnt[4];
    }
};