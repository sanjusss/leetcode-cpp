/*
 * @Author: sanjusss
 * @Date: 2023-01-21 09:24:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-21 09:53:02
 * @FilePath: \1000\1800\1820\1824.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int c1 = 1;
        int c2 = 0;
        int c3 = 1;
        for (int i : obstacles) {
            int n1 = i == 1 ? INT_MAX / 2 : c1;
            int n2 = i == 2 ? INT_MAX / 2 : c2;
            int n3 = i == 3 ? INT_MAX / 2 : c3;
            c1 = i == 1 ? INT_MAX / 2 : min(min(n2, n3) + 1, n1);
            c2 = i == 2 ? INT_MAX / 2 : min(min(n1, n3) + 1, n2);
            c3 = i == 3 ? INT_MAX / 2 : min(min(n1, n2) + 1, n3);
        }
        
        return min({ c1, c2, c3 });
    }
};

TEST(&Solution::minSideJumps)