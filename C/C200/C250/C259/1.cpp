/*
 * @Author: sanjusss
 * @Date: 2021-09-19 10:33:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-19 10:34:57
 * @FilePath: \C\C200\C250\C259\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (string& i : operations) {
            if (i == "++X"s || i == "X++"s) {
                ++ans;
            }
            else {
                --ans;
            }
        }

        return ans;
    }
};