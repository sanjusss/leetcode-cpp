/*
 * @Author: sanjusss
 * @Date: 2022-05-22 10:29:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-22 10:36:51
 * @FilePath: \C\C200\C290\C294\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int, vector<int>, greater<>> q;
        int n = capacity.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int diff = capacity[i] - rocks[i];
            if (diff > 0) {
                q.push(diff);
            }
            else {
                ++ans;
            }
        }

        while (!q.empty() && q.top() <= additionalRocks) {
            additionalRocks -= q.top();
            q.pop();
            ++ans;
        }

        return ans;
    }
};