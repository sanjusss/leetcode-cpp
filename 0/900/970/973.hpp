#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//         priority_queue<pair<int, int>> q;
//         for (int i = 0; i < points.size(); ++i) {
//             int val = points[i][0] * points[i][0] + points[i][1] * points[i][1];
//             if (q.size() == K) {
//                 if (q.top().first > val) {
//                     q.pop();
//                     q.emplace(val, i);
//                 }
//             }
//             else {
//                 q.emplace(val, i);
//             }
//         }

//         vector<vector<int>> ans;
//         while (!q.empty()) {
//             ans.push_back(points[q.top().second]);
//             q.pop();
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K, points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });

        points.resize(K);
        return points;
    }
};