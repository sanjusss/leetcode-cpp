/*
 * @Author: sanjusss
 * @Date: 2021-07-30 08:48:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-30 08:58:35
 * @FilePath: \chengxuyuanmianshijindian\0103.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string replaceSpaces(string S, int length) {
        int cur = length;
        for (int i = 0; i < length; ++i) {
            if (S[i] == ' ') {
                cur += 2;
            }
        }

        S.resize(cur--);
        for (int i = length - 1; i >= 0; --i) {
            if (S[i] == ' ') {
                S[cur--] = '0';
                S[cur--] = '2';
                S[cur--] = '%';
            }
            else {
                S[cur--] = S[i];
            }
        }

        return S;
    }
};