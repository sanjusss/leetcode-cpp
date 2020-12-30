/*
 * @Author: sanjusss
 * @Date: 2020-12-30 14:27:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-30 15:51:38
 * @FilePath: \1000\1000\1040\1046.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if (a != b) {
                q.push(a - b);
            }
        }
        
        if (q.empty()) {
            return 0;
        }
        else {
            return q.top();
        }
    }
};