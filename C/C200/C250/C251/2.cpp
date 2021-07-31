/*
 * @Author: sanjusss
 * @Date: 2021-07-25 10:37:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-25 10:43:56
 * @FilePath: \C\C200\C250\C251\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool done = false;
        for (char& i : num) {
            int v = i - '0';
            if (change[v] > v || (change[v] == v && done)) {
                i = change[v] + '0';
                done = true;
            }
            else if (done) {
                break;
            }
        }

        return num;
    }
};