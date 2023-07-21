/*
 * @Author: sanjusss
 * @Date: 2023-07-21 08:55:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-21 09:06:58
 * @FilePath: \1000\1400\1490\1499.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
//         auto cmp = [&points] (int a, int b) {
//             return (points[a][1] - points[a][0]) < (points[b][1] - points[b][0]);
//         };
//         priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
//         int n = points.size();
//         int ans = INT_MIN;
//         for (int i = 0; i < n; ++i) {
//             while (!q.empty() && points[i][0] - points[q.top()][0] > k) {
//                 q.pop();
//             }

//             if (!q.empty()) {
//                 ans = max(ans, points[i][1] + points[q.top()][1] + (points[i][0] - points[q.top()][0]));
//             }

//             q.push(i);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ans = INT_MIN;
        deque<int> q;
        for (int i = 0; i < n; ++i) {
            while (!q.empty() && points[i][0] - points[q.front()][0] > k) {
                q.pop_front();
            }

            if (!q.empty()) {
                ans = max(ans, points[i][1] + points[q.front()][1] + (points[i][0] - points[q.front()][0]));
            }

            while (!q.empty() && (points[q.back()][1] - points[q.back()][0]) <= (points[i][1] - points[i][0])) {
                q.pop_back();
            }

            q.push_back(i);
        }

        return ans;
    }
};