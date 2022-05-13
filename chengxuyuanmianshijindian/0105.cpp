/*
 * @Author: sanjusss
 * @Date: 2022-05-13 08:43:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-13 08:48:34
 * @FilePath: \chengxuyuanmianshijindian\0105.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n = first.size();
        int m = second.size();
        if (n == m) {
            int diff = 0;
            for (int i = 0; i < n && diff < 2; ++i) {
                if (first[i] != second[i]) {
                    ++diff;
                }
            }

            return diff <= 1;
        }
        else if (n + 1 == m) {
            int diff = 0;
            int i = 0;
            for (int j = 0; j < m && diff < 2; ++j) {
                if (first[i] != second[j]) {
                    ++diff;
                }
                else {
                    ++i;
                }
            }

            return diff <= 1;
        }
        else if (n - 1 == m) {
            int diff = 0;
            int j = 0;
            for (int i = 0; i < n && diff < 2; ++i) {
                if (first[i] != second[j]) {
                    ++diff;
                }
                else {
                    ++j;
                }
            }

            return diff <= 1;
        }
        else {
            return false;
        }
    }
};