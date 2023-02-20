/*
 * @Author: sanjusss
 * @Date: 2023-02-20 10:36:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-20 10:46:35
 * @FilePath: \2000\2300\2340\2347.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool isFlush = true;
        for (int i = 1; i < 5; ++i) {
            if (suits[i] != suits[i - 1]) {
                isFlush = false;
                break;
            }
        }

        if (isFlush) {
            return "Flush"s;
        }

        int maxLen = 0;
        int len = 0;
        int pre = 0;
        sort(ranks.begin(), ranks.end());
        for (int i : ranks) {
            if (i == pre) {
                ++len;
            }
            else {
                len = 1;
            }

            pre = i;
            maxLen = max(maxLen, len);
        }

        if (maxLen >= 3) {
            return "Three of a Kind"s;
        }
        else if (maxLen == 2) {
            return "Pair"s;
        }
        else {
            return "High Card"s;
        }
    }
};