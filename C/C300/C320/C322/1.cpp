/*
 * @Author: sanjusss
 * @Date: 2022-11-27 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-04 10:32:38
 * @FilePath: \C\C300\C320\C322\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        for (int i = 0; i < n; ++i) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }

        return sentence.front() == sentence.back();
    }
};