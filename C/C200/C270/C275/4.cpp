/*
 * @Author: sanjusss
 * @Date: 2022-01-09 10:26:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-09 11:24:29
 * @FilePath: \C\C200\C270\C275\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> is(n);
        iota(is.begin(), is.end(), 0);
        sort(is.begin(), is.end(), [&](int a, int b) {
            if (growTime[a] == growTime[b]) {
                return plantTime[a] > plantTime[b];
            }
            else {
                return growTime[a] > growTime[b];
            }
        });
        int plant = 0;
        int ans = 0;
        for (int i : is) {
            plant += plantTime[i];
            ans = max(ans, plant + growTime[i]); 
        }

        return ans;
    }
};

TEST(&Solution::earliestFullBloom)