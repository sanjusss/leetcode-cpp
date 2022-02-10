/*
 * @Author: sanjusss
 * @Date: 2022-02-10 10:47:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-10 10:49:06
 * @FilePath: \1000\1400\1440\1447.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (gcd(i, j) == 1) {
                    ans.push_back(to_string(j) + "/"s + to_string(i));
                }
            }
        }

        return ans;
    }
};