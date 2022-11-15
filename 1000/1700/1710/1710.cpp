/*
 * @Author: sanjusss
 * @Date: 2022-11-15 08:29:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-15 08:36:19
 * @FilePath: \1000\1700\1710\1710.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto cmp = [&boxTypes] (int a, int b) {
            return boxTypes[a][1] < boxTypes[b][1];
        };
        int n = boxTypes.size();
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for (int i = 0; i < n; ++i) {
            q.push(i);
        }

        int ans = 0;
        while (truckSize > 0 && !q.empty()) {
            int i = q.top();
            q.pop();
            int b = min(truckSize, boxTypes[i][0]);
            truckSize -= b;
            ans += b * boxTypes[i][1];
        }

        return ans;
    }
};