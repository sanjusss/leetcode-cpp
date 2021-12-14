/*
 * @Author: sanjusss
 * @Date: 2021-12-14 09:57:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-14 10:55:55
 * @FilePath: \0\600\630\630.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

        priority_queue<int> q;
        int total = 0;
        for (auto& c : courses) {
            if (total + c[0] > c[1]) {
                if (!q.empty() && q.top() > c[0]) {
                    total -= q.top();
                    q.pop();
                    q.push(c[0]);
                    total += c[0];
                }
            }
            else {
                q.push(c[0]);
                total += c[0];
            }
        }

        return q.size();
    }
};

TEST(&Solution::scheduleCourse)