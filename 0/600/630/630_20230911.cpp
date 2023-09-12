/*
 * @Author: sanjusss
 * @Date: 2023-09-11 08:56:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-11 10:04:39
 * @FilePath: \0\600\630\630_20230911.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [] (const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> q;
        int sum = 0;
        for (auto& c : courses) {
            if (sum + c[0] > c[1]) {
                if (!q.empty() && q.top() > c[0]) {
                    sum -= q.top();
                    q.pop();
                    sum += c[0];
                    q.push(c[0]);
                }
            }
            else {
                q.push(c[0]);
                sum += c[0];
            }
        }

        return q.size();
    }
};

TEST(&Solution::scheduleCourse)