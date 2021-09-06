/*
 * @Author: sanjusss
 * @Date: 2021-09-06 08:23:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-06 08:25:12
 * @FilePath: \LCP\000\00\01.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int ans = 0;
        for (int i = 0; i < 3; ++i) {
            if (guess[i] == answer[i]) {
                ++ans;
            }
        }

        return ans;
    }
};