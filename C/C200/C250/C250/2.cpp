/*
 * @Author: sanjusss
 * @Date: 2021-07-18 10:35:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-18 10:42:23
 * @FilePath: \C\C200\C250\C250\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {    
        int ans = 0;
        int prev = 0;
        for (int i : rungs) {
            ans += max(i - prev - 1, 0) / dist;
            prev = i;
        }

        return ans;
    }
};

TEST(&Solution::addRungs)