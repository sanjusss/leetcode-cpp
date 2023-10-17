/*
 * @Author: sanjusss
 * @Date: 2023-10-17 09:44:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-10-17 09:47:25
 * @FilePath: \2000\2600\2650\2652.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int sumOfMultiples(int n) {
        auto calc = [n] (int m) {
            int cnt = n / m;
            return (m + m * cnt) * cnt / 2;
        };
        return calc(3) + calc(5) + calc(7) - calc(3 * 5) - calc(3 * 7) - calc(5 * 7) + calc(3 * 5 * 7);
    }
};