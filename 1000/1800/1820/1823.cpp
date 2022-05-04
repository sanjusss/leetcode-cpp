/*
 * @Author: sanjusss
 * @Date: 2022-05-04 13:13:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-04 13:36:57
 * @FilePath: \1000\1800\1820\1823.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            ans = (ans + k) % i; 
        }

        return ans + 1;
    }
};