/*
 * @Author: sanjusss
 * @Date: 2022-02-13 10:30:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-13 10:33:12
 * @FilePath: \C\C200\C280\C280\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while (num1 != 0 && num2 != 0) {
            tie(num1, num2) = make_pair(abs(num1 - num2), min(num1, num2));
            ++ans;
        }

        return ans;
    }
};