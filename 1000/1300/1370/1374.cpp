/*
 * @Author: sanjusss
 * @Date: 2022-08-01 08:29:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-01 08:29:18
 * @FilePath: \1000\1300\1370\1374.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string generateTheString(int n) {
        if (n % 2 == 0) {
            return string(n - 1, 'a') + 'b';
        }
        else {
            return string(n, 'a');
        }
    }
};