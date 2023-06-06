/*
 * @Author: sanjusss
 * @Date: 2023-06-07 05:41:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-07 05:46:04
 * @FilePath: \2000\2600\2610\2611.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int sum = 0;
        priority_queue<int> q;
        for (int i = 0; i < n; ++i) {
            sum += reward1[i];
            q.emplace(reward2[i] - reward1[i]);
            if (q.size() > k) {
                sum += q.top();
                q.pop();
            }
        }

        return sum;
    }
};