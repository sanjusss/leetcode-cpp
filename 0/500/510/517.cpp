/*
 * @Author: sanjusss
 * @Date: 2021-09-29 19:58:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-29 20:26:58
 * @FilePath: \0\500\510\517.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (sum % n != 0) {
            return -1;
        }

        int avg = sum / n;
        int ans = 0;
        int needs = 0;
        for (int i : machines) {
            needs += avg - i;
            ans = max({ ans, abs(needs), i - avg });
        }

        return ans;
    }
};

TEST(&Solution::findMinMoves)