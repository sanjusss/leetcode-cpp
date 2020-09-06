#pragma once
#include "leetcode.h"

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        char last = 0;
        int lastCost = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == last) {
                if (lastCost <= cost[i]) {
                    ans += lastCost;
                    lastCost = cost[i];
                }
                else {
                    ans += cost[i];
                }
            }
            else {
                last = s[i];
                lastCost = cost[i];
            }
        }

        return ans;
    }
};