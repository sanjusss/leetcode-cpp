/*
 * @Author: sanjusss
 * @Date: 2021-09-10 08:28:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-10 08:45:40
 * @FilePath: \1000\1800\1890\1894.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        for (int& i : chalk) {
            if (INT_MAX - i >= sum) {
                sum += i;
            }
            else {
                sum = INT_MAX;
            }
            
            i = sum;
        }

        k %= sum;
        return upper_bound(chalk.begin(), chalk.end(), k) - chalk.begin();
    }
};

TEST(&Solution::chalkReplacer)