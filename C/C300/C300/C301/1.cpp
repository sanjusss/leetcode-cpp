/*
 * @Author: sanjusss
 * @Date: 2022-07-10 10:30:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-10 10:33:07
 * @FilePath: \C\C300\C300\C301\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[2] >= amount[0] + amount[1]) {
            return amount[2];
        }
        else {
            return (amount[0] + amount[1] + amount[2] + 1) / 2;
        }
    }
};